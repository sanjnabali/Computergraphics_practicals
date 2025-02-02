#include <graphics.h>
#include <stdio.h>

// Define region codes
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Global clipping window boundaries
int x_min, y_min, x_max, y_max;

// Function to calculate region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min) code |= LEFT;
    else if (x > x_max) code |= RIGHT;
    if (y < y_min) code |= BOTTOM;
    else if (y > y_max) code |= TOP;

    return code;
}

// Function to perform Cohen-Sutherland line clipping
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;
    int clipped = 0; // Flag to check if clipping was done

    // Draw the initial line in red
    setcolor(RED);
    line(x1, y1, x2, y2);

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints are inside the clipping window
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Both endpoints are in an outside region, reject the line
            break;
        } else {
            // Clipping is required
            int codeOut;
            int x, y;

            // Select an endpoint that is outside the clipping window
            if (code1 != 0) codeOut = code1;
            else codeOut = code2;

            // Find intersection point
            if (codeOut & TOP) { // Point is above the clipping window
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (codeOut & BOTTOM) { // Point is below the clipping window
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (codeOut & RIGHT) { // Point is to the right of clipping window
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (codeOut & LEFT) { // Point is to the left of clipping window
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace outside endpoint with intersection point and update code
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }

            clipped = 1; // Set flag indicating clipping was performed
        }
    }

    if (accept) {
        // If the line segment was accepted, draw it in green
        setcolor(GREEN);
        line(x1, y1, x2, y2);

        // Print message based on whether clipping was done
        if (clipped) {
            printf("Line clipped and accepted from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
        } else {
            printf("Line fully inside and accepted from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
        }
    } else {
        printf("Line rejected as it is completely outside the clipping window.\n");
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Get user input for clipping window boundaries
    printf("Enter the clipping window boundaries:\n");
    printf("x_min y_min: ");
    scanf("%d %d", &x_min, &y_min);
    printf("x_max y_max: ");
    scanf("%d %d", &x_max, &y_max);

    // Draw clipping window in white
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Get user input for line endpoints
    int x1, y1, x2, y2;
    printf("Enter the endpoints of the line segment:\n");
    printf("x1 y1: ");
    scanf("%d %d", &x1, &y1);
    printf("x2 y2: ");
    scanf("%d %d", &x2, &y2);

    // Apply the Cohen-Sutherland clipping algorithm
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
