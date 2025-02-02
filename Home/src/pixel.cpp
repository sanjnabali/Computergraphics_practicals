#include <graphics.h>
#include <stdio.h>

int main() {
    // Initialize the graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the point
    int x = 200, y = 200;

    // Plot the point
    putpixel(x, y, WHITE); // WHITE is the color of the pixel

    // Hold the screen
    printf("A point is plotted at (%d, %d). Press any key to exit...\n", x, y);
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}
