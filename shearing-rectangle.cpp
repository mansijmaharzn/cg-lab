// By: Nalim Bhai
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void shearX(int x[], int y[], int shx) {
    int i;
    for (i = 0; i < 4; i++)
        x[i] += shx * y[i];
}

void shearY(int x[], int y[], int shy) {
    int i;
    for (i = 0; i < 4; i++)
        y[i] += shy * x[i];
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x[] = {10, 20, 20, 10};
    int y[] = {10, 10, 20, 20};
    
    int shearXValue = 2;
    int shearYValue = 2;

    // Original rectangle
    setcolor(RED);
    rectangle(x[0], y[0], x[2], y[2]);

    // Shear along X-axis
    shearX(x, y, shearXValue);
    setcolor(GREEN);
    rectangle(x[0], y[0], x[2], y[2]);

    // Reset the coordinates
    x[0] = 10, y[0] = 10;
    x[1] = 20, y[1] = 10;
    x[2] = 20, y[2] = 20;
    x[3] = 10, y[3] = 20;

    // Shear along Y-axis
    shearY(x, y, shearYValue);
    setcolor(BLUE);
    rectangle(x[0], y[0], x[2], y[2]);

    // Reset the coordinates
    x[0] = 10, y[0] = 10;
    x[1] = 20, y[1] = 10;
    x[2] = 20, y[2] = 20;
    x[3] = 10, y[3] = 20;

    // Shear along both X and Y axes
    shearX(x, y, shearXValue);
    shearY(x, y, shearYValue);
    setcolor(YELLOW);
    rectangle(x[0], y[0], x[2], y[2]);

    getch();
    closegraph();
    return 0;
}
