#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to perform Flood-Fill algorithm
void floodFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    
    // Check if the current pixel is not the boundary color and is not the fill color
    if (x >= 0 && x < getmaxx() && y >= 0 && y < getmaxy() && currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor); // Set pixel to fill color
        
        // Recursive calls for surrounding pixels
        floodFill(x + 1, y, fillColor, boundaryColor);
        floodFill(x - 1, y, fillColor, boundaryColor);
        floodFill(x, y + 1, fillColor, boundaryColor);
        floodFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    // Draw a filled rectangle
    setcolor(WHITE);
    rectangle(100, 100, 300, 300);
    floodFill(150, 150, YELLOW, WHITE); // Fill inside the rectangle
    
    getch(); // Wait for user input
    closegraph();
    return 0;
}
