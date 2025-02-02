#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main() {
    int gd = DETECT, gm;
    int x, y, size = 50; // Size of the square

    // Initialize graphics window
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Click anywhere to draw a square. Press any key to exit.\n");

    while (!kbhit()) { // Run until a key is pressed
        if (ismouseclick(WM_LBUTTONDOWN)) { // Check if left mouse button is clicked
            getmouseclick(WM_LBUTTONDOWN, x, y); // Get mouse click coordinates
            rectangle(x, y, x + size, y + size); // Draw a square at the clicked position
        }
    }

    closegraph(); // Close graphics window
}
