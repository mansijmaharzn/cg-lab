#include <graphics.h>
#include <stdio.h>
#include<math.h>

void draw(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 2);
    putpixel(xc - x, yc + y, 6);
    putpixel(xc + x, yc - y, 5);
    putpixel(xc - x, yc - y, 9);
}

void drawEllipse(int xc, int yc, int a, int b) {
    int x = 0;
    int y = b;

    int a_sqr = a * a;
    int b_sqr = b * b;
    int two_a_sqr = 2 * a_sqr;
    int two_b_sqr = 2 * b_sqr;

    int p;
    int px = 0;
    int py = two_a_sqr * y;

    // Region 1
    p = b_sqr - (a_sqr * b) + (0.25 * a_sqr);

    while (px < py) {
        draw(xc, yc, x, y);

        x++;
        px += two_b_sqr;

        if (p < 0) {
            p += b_sqr + px;
        } else {
            y--;
            py -= two_a_sqr;
            p += b_sqr + px - py;
        }
    }

    // Region 2
    p = b_sqr * (x + 0.5) * (x + 0.5) + a_sqr * (y - 1) * (y - 1) - a_sqr * b_sqr;

    while (y >= 0) {
        draw(xc, yc, x, y);

        y--;
        py -= two_a_sqr;

        if (p > 0) {
            p += a_sqr - py;
        } else {
            x++;
            px += two_b_sqr;
            p += a_sqr - py + px;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, a, b;

    printf("Enter the coordinates of the center (xc, yc): ");
    scanf("%d%d", &xc, &yc);

    printf("Enter the major axis (a): ");
    scanf("%d", &a);

    printf("Enter the minor axis (b): ");
    scanf("%d", &b);

    drawEllipse(xc, yc, a, b);

    getch();
    closegraph();

    return 0;
}

/* 
translate a straight line
rotation of a triangle - about origin, about fixed point
scale a traingle and triangle - about

*/
