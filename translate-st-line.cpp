#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to draw a straight line
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to translate a line by (tx, ty)
void translateLine(int *x1, int *y1, int *x2, int *y2, int tx, int ty) {
    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2; // Coordinates of the line endpoints
    int tx, ty; // Translation vector

    // Input the coordinates of the line
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Draw the initial line
    drawLine(x1, y1, x2, y2);

    // Input the translation vector
    printf("Enter the translation vector (tx ty): ");
    scanf("%d %d", &tx, &ty);

    // Translate the line
    translateLine(&x1, &y1, &x2, &y2, tx, ty);

    // Draw the translated line
    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}

