#include <graphics.h>
#include <stdio.h>

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Set the background to black
    setbkcolor(BLACK);
    cleardevice(); // Clear the screen with the background color

    // Set drawing color
    setcolor(WHITE);

    // Coordinates of the rectangle
    int left = 100, top = 100, right = 300, bottom = 200;

    // Draw the rectangle
    rectangle(left, top, right, bottom);

    // Hold the screen
    printf("A rectangle is drawn on a black background. Press any key to exit...\n");
    getch();

    // Close graphics mode
    closegraph();
    return 0;
}
