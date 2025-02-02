#include <graphics.h>
#include <stdio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    // Calculate differences
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate increments
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    // Initialize starting point
    float x = x1;
    float y = y1;

    // Draw the pixels
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Plot the point
        x += xInc;
        y += yInc;
    }
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Input start and end points
    int x1 = 100, y1 = 100, x2 = 300, y2 = 300;

    // Call DDA function
    DDA(x1, y1, x2, y2);

    // Hold screen until a key is pressed
    printf("Line drawn using DDA algorithm. Press any key to exit...\n");
    getch();

    // Close graphics mode
    closegraph();
    return 0;
}
