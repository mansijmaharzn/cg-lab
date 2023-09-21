// By: Sachana
#include <graphics.h>

// Function to draw a quadratic Bezier curve
void drawQuadraticBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    

    int numberOfPoints = 1000;  // Number of points to interpolate
    float t, step;
    int x, y;

    step = 1.0 / numberOfPoints;
    t = 0.0;

    for (int i = 0; i <= numberOfPoints; i++) {
        x = (1 - t) * (1 - t) * (1 - t) * x0 + 3 * (1 - t) * (1 - t) * t * x1
            + 3 * (1 - t) * t * t * x2 + t * t * t * x3;

        y = (1 - t) * (1 - t) * (1 - t) * y0 + 3 * (1 - t) * (1 - t) * t * y1
            + 3 * (1 - t) * t * t * y2 + t * t * t * y3;

        putpixel(x, y, WHITE);

        t += step;
    }

    getch();
    closegraph();
}

int main() {
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    int x0, y0, x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates of the control points:\n");
    printf("Point 0 (x y): ");
    scanf("%d %d", &x0, &y0);
    printf("Point 1 (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 2 (x y): ");
    scanf("%d %d", &x2, &y2);
    printf("Point 3 (x y): ");
    scanf("%d %d", &x3, &y3);

    drawQuadraticBezier(x0, y0, x1, y1, x2, y2, x3, y3);

    return 0;
}
