// By: Sachana
#include <graphics.h>

// Function to draw a quadratic Bezier curve
void drawQuadraticBezier(int x0, int y0, int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int numberOfPoints = 1000;  // Number of points to interpolate
    float t, step;
    int x, y;

    step = 1.0 / numberOfPoints;
    t = 0.0;

    for (int i = 0; i <= numberOfPoints; i++) {
        x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
        y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;

        putpixel(x, y, WHITE);

        t += step;
    }

    getch();
    closegraph();
}

int main() {
    int x0, y0, x1, y1, x2, y2;

    printf("Enter coordinates of the control points:\n");
    printf("Point 0 (x,y): ");
    scanf("%d %d", &x0, &y0);
    printf("Point 1 (x,y): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 2 (x,y): ");
    scanf("%d %d", &x2, &y2);

    drawQuadraticBezier(x0, y0, x1, y1, x2, y2);

    return 0;
}
