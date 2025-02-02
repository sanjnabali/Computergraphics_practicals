#include <graphics.h>
#include <stdio.h>

// Function to reflect a point about the x-axis
void reflectX(int midY, int x, int y, int *refX, int *refY) {
    *refX = x;
    *refY = midY - (y - midY);
}

// Function to reflect a point about the y-axis
void reflectY(int midX, int midY, int x, int y, int *refX, int *refY) {
    *refX = midX - (x - midX);
    *refY = y;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Original triangle coordinates
    int x1 = 200, y1 = 150;
    int x2 = 250, y2 = 250;
    int x3 = 150, y3 = 250;

    // Draw the original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Midpoint for reflections
    int midX = 200; // x-coordinate for y-axis reflection
    int midY = 200; // y-coordinate for x-axis reflection

    // Reflecting triangle about the x-axis
    int rx1, ry1, rx2, ry2, rx3, ry3;
    reflectX(midY, x1, y1, &rx1, &ry1);
    reflectX(midY, x2, y2, &rx2, &ry2);
    reflectX(midY, x3, y3, &rx3, &ry3);

    setcolor(YELLOW); // Color for x-axis reflection
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);

    // Reflecting triangle about the y-axisB
    int yx1, yy1, yx2, yy2, yx3, yy3;
    reflectY(midX, midY, x1, y1, &yx1, &yy1);
    reflectY(midX, midY, x2, y2, &yx2, &yy2);
    reflectY(midX, midY, x3, y3, &yx3, &yy3);

    setcolor(CYAN); // Color for y-axis reflection
    line(yx1, yy1, yx2, yy2);
    line(yx2, yy2, yx3, yy3);
    line(yx3, yy3, yx1, yy1);

    getch(); // Wait for user input
    closegraph();
    return 0;
}
