// By: Nalim Bhai
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// B�zier curve function for 3 points
void drawBezier3(int x[4], int y[4]) {
    int i;
    double t;

    for (t = 0.0; t <= 1.0; t += 0.001) {
        double xt = pow(1 - t, 2) * x[0] + 2 * (1 - t) * t * x[1] + pow(t, 2) * x[2];
        double yt = pow(1 - t, 2) * y[0] + 2 * (1 - t) * t * y[1] + pow(t, 2) * y[2];

        putpixel(xt, yt, WHITE);
    }
}

// B�zier curve function for 4 points
void drawBezier4(int x[5], int y[5]) {
    int i;
    double t;

    for (t = 0.0; t <= 1.0; t += 0.001) {
        double xt = pow(1 - t, 3) * x[0] + 3 * pow(1 - t, 2) * t * x[1] + 3 * (1 - t) * pow(t, 2) * x[2] + pow(t, 3) * x[3];
        double yt = pow(1 - t, 3) * y[0] + 3 * pow(1 - t, 2) * t * y[1] + 3 * (1 - t) * pow(t, 2) * y[2] + pow(t, 3) * y[3];

        putpixel(xt, yt, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x3[3] = {100, 300, 500};
    int y3[3] = {400, 100, 400};

    int x4[4] = {100, 200, 400, 500};
    int y4[4] = {400, 100, 100, 400};

    drawBezier3(x3, y3);
    drawBezier4(x4, y4);

    getch();
    closegraph();
    return 0;
}
