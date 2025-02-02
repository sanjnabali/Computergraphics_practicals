#include <graphics.h>
#include <math.h>
#include <stdio.h>

// Function to rotate a point about a fixed point
void rotatePoint(float px, float py, float cx, float cy, float angle, float *newX, float *newY) {
    // Convert angle to radians
    float rad = angle * M_PI / 180;

    // Translate point to origin
    float translatedX = px - cx;
    float translatedY = py - cy;

    // Apply rotation
    *newX = translatedX * cos(rad) - translatedY * sin(rad) + cx;
    *newY = translatedX * sin(rad) + translatedY * cos(rad) + cy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Initial coordinates of the triangle's vertices
    float x1 = 100, y1 = 100;
    float x2 = 150, y2 = 50;
    float x3 = 200, y3 = 100;

    // Fixed point (center of rotation)
    float cx = 150, cy = 100;

    // Rotation angle
    float angle = 45; // Rotate by 45 degrees

    // Draw the original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Draw the fixed point
    setcolor(RED);
    circle(cx, cy, 2);

    // Wait for user input
    printf("Press any key to rotate the triangle...\n");
    getch();

    // Rotate each vertex
    float nx1, ny1, nx2, ny2, nx3, ny3;
    rotatePoint(x1, y1, cx, cy, angle, &nx1, &ny1);
    rotatePoint(x2, y2, cx, cy, angle, &nx2, &ny2);
    rotatePoint(x3, y3, cx, cy, angle, &nx3, &ny3);

    // Clear the screen
    cleardevice();

    // Draw the rotated triangle
    setcolor(WHITE);
    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    // Draw the fixed point
    setcolor(RED);
    circle(cx, cy, 2);

    // Wait for another key press before exiting
    printf("Press any key to exit...\n");
    getch();

    closegraph();
    return 0;
}
