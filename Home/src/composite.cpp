#include <graphics.h>
#include <math.h>
#include <stdio.h>

// Function to apply translation to a point
void translatePoint(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

// Function to apply scaling to a point with respect to a fixed point (fx, fy)
void scalePoint(int *x, int *y, int fx, int fy, float sx, float sy) {
    *x = fx + (*x - fx) * sx;
    *y = fy + (*y - fy) * sy;
}

// Function to rotate a point around an arbitrary point (px, py) by an angle theta
void rotatePoint(int *x, int *y, int px, int py, float theta) {
    float radian = theta * M_PI / 180; // Convert angle from degrees to radians
    int tempX = *x - px;
    int tempY = *y - py;

    *x = px + (tempX * cos(radian) - tempY * sin(radian));
    *y = py + (tempX * sin(radian) + tempY * cos(radian));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Initial coordinates of the square
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    // Composite transformation parameters
    int tx = 50, ty = 50;        // Translation values
    float angle = 45;             // Rotation angle
    float sx = 1.5, sy = 1.5;     // Scaling factors
    int px = 150, py = 150;       // Point about which to rotate and scale

    // Draw original square
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    // Apply translation to each vertex
    translatePoint(&x1, &y1, tx, ty);
    translatePoint(&x2, &y2, tx, ty);
    translatePoint(&x3, &y3, tx, ty);
    translatePoint(&x4, &y4, tx, ty);

    // Apply rotation to each vertex
    rotatePoint(&x1, &y1, px, py, angle);
    rotatePoint(&x2, &y2, px, py, angle);
    rotatePoint(&x3, &y3, px, py, angle);
    rotatePoint(&x4, &y4, px, py, angle);

    // Apply scaling to each vertex
    scalePoint(&x1, &y1, px, py, sx, sy);
    scalePoint(&x2, &y2, px, py, sx, sy);
    scalePoint(&x3, &y3, px, py, sx, sy);
    scalePoint(&x4, &y4, px, py, sx, sy);

    // Draw transformed square
    setcolor(YELLOW);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    getch();
    closegraph();
    return 0;
}
