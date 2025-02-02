#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

// Define clipping window boundaries
int x_min, y_min, x_max, y_max;

// Structure for a point
typedef struct {
    int x, y;
} Point;

// Function to calculate intersection point
Point intersect(Point p1, Point p2, int edge, int isVertical) {
    Point intersection;
    if (isVertical) { // Vertical edge (x = edge)
        intersection.x = edge;
        intersection.y = p1.y + (p2.y - p1.y) * (edge - p1.x) / (p2.x - p1.x);
    } else { // Horizontal edge (y = edge)
        intersection.y = edge;12
        intersection.x = p1.x + (p2.x - p1.x) * (edge - p1.y) / (p2.y - p1.y);
    }
    return intersection;
}

// Function to check if a point is inside the clipping boundary
int isInside(Point p, int edge, int isVertical, int isMinBoundary) {
    if (isVertical) {
        return isMinBoundary ? p.x >= edge : p.x <= edge;
    } else {
        return isMinBoundary ? p.y >= edge : p.y <= edge;
    }
}

// Sutherland-Hodgman polygon clipping function
int clipPolygon(Point in[], int inCount, Point out[], int edge, int isVertical, int isMinBoundary) {
    int outCount = 0;

    for (int i = 0; i < inCount; i++) {
        Point current = in[i];
        Point prev = in[(i - 1 + inCount) % inCount];

        int currentInside = isInside(current, edge, isVertical, isMinBoundary);
        int prevInside = isInside(prev, edge, isVertical, isMinBoundary);

        if (currentInside && prevInside) {
            // Both points are inside
            out[outCount++] = current;
        } else if (prevInside && !currentInside) {
            // Leaving the boundary
            out[outCount++] = intersect(prev, current, edge, isVertical);
        } else if (!prevInside && currentInside) {
            // Entering the boundary
            out[outCount++] = intersect(prev, current, edge, isVertical);
            out[outCount++] = current;
        }
    }

    return outCount;
}

void sutherlandHodgmanClipping(Point polygon[], int n) {
    Point temp[20];
    int count = n;

    // Clip against each boundary of the rectangle
    count = clipPolygon(polygon, count, temp, x_min, 1, 1); // Left boundary
    count = clipPolygon(temp, count, polygon, y_min, 0, 1); // Bottom boundary
    count = clipPolygon(polygon, count, temp, x_max, 1, 0); // Right boundary
    count = clipPolygon(temp, count, polygon, y_max, 0, 0); // Top boundary

    // Draw the clipped polygon
    setcolor(GREEN);
    for (int i = 0; i < count; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % count].x, polygon[(i + 1) % count].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Input the clipping window
    printf("Enter the clipping window boundaries:\n");
    printf("x_min y_min: ");
    scanf("%d %d", &x_min, &y_min);
    printf("x_max y_max: ");
    scanf("%d %d", &x_max, &y_max);

    // Draw the clipping window
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Input the polygon vertices
    int n;
    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);

    Point polygon[20];
    printf("Enter the vertices of the polygon (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    // Draw the original polygon
    setcolor(RED);
    for (int i = 0; i < n; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % n].x, polygon[(i + 1) % n].y);
    }

    // Perform clipping
    sutherlandHodgmanClipping(polygon, n);

    getch();
    closegraph();
    return 0;
}
