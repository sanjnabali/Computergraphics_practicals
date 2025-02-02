#include <graphics.h>
#include <stdio.h>

// Function to fill the rectangle using the scan-line algorithm
void scanLineFill(int x_min, int y_min, int x_max, int y_max, int color) {
    for (int y = y_min; y <= y_max; y++) {
        for (int x = x_min; x <= x_max; x++) {
            putpixel(x, y, color);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Input rectangle coordinates and color
    int x_min, y_min, x_max, y_max, fill_color;
    printf("Enter the coordinates of the rectangle:\n");
    printf("Bottom-left corner (x_min y_min): ");
    scanf("%d %d", &x_min, &y_min);
    printf("Top-right corner (x_max y_max): ");
    scanf("%d %d", &x_max, &y_max);
    printf("Enter the color code for filling (0-15): ");
    scanf("%d", &fill_color);

    // Draw the rectangle outline
    setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);

    // Perform scan-line fill
    scanLineFill(x_min, y_min, x_max, y_max, fill_color);

    printf("Rectangle filled with color code %d.\n", fill_color);
    getch();
    closegraph();
    return 0;
}
