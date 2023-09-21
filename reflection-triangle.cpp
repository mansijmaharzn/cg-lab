// By: Nalim Bhai
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to reflect a point about y = x line
void reflectYEqualsX(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reflect a point about y = mx + c line
void reflectLine(int *x, int *y, float m, float c) {
    int temp = *x;
    *x = (int) ((*x - (2 * m * (*y) - 2 * c) / (1 + 2 * m * m)));
    *y = (int) (2 * m * temp + 2 * c - *y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1 = 50, y1 = 50;
    int x2 = 50, y2 = 100;
    int x3 = 100, y3 = 100;

    // Draw the original triangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Reflect about y = x
    reflectYEqualsX(&x1, &y1);
    reflectYEqualsX(&x2, &y2);
    reflectYEqualsX(&x3, &y3);

    // Draw the reflected triangle
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Reflect about y = mx + c
    float m = 1.5; // slope
    float c = 3;  // y-intercept
    reflectLine(&x1, &y1, m, c);
    reflectLine(&x2, &y2, m, c);
    reflectLine(&x3, &y3, m, c);

    // Draw the doubly reflected triangle
    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
    return 0;
}
