#include <graphics.h>
#include <math.h>
#include <stdio.h>

// Function to rotate a point (x, y) around an arbitrary point (px, py) by an angle theta
void rotatePoint(int *x, int *y, int px, int py, float theta) {
    float radian = theta * M_PI / 180; // Convert angle from degrees to radians
    int tempX = *x, tempY = *y;

    // Translate point back to origin
    tempX -= px;
    tempY -= py;

    // Rotate point
    *x = px + (tempX * cos(radian) - tempY * sin(radian));
    *y = py + (tempX * sin(radian) + tempY * cos(radian));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100; // Triangle vertex 1
    int x2 = 200, y2 = 100; // Triangle vertex 2
    int x3 = 150, y3 = 50;  // Triangle vertex 3

    int px = 150, py = 150; // Arbitrary point about which to rotate
    float angle = 45;       // Rotation angle

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Rotate each vertex of the triangle
    rotatePoint(&x1, &y1, px, py, angle);
    rotatePoint(&x2, &y2, px, py, angle);
    rotatePoint(&x3, &y3, px, py, angle);

    // Draw rotated triangle
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Mark the arbitrary point
    setcolor(RED);
    circle(px, py, 5);

    getch();
    closegraph();
    return 0;
}
