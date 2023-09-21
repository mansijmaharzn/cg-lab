// By: Sachana
#include <graphics.h>
#include <math.h>


void reflectYEqualsX(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

void reflectYEqualsMXPlusC(float *x, float *y, float m, float c) {
    float tempX = *x;
    *x = ((*x) + (*y) - 2 * m * (c + (*x))) / (1 + m * m);
    *y = m * ((*x) - tempX) + c;
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    line(centerX + x1, centerY - y1, centerX + x2, centerY - y2);
    line(centerX + x2, centerY - y2, centerX + x3, centerY - y3);
    line(centerX + x3, centerY - y3, centerX + x1, centerY - y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates of the triangle:\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    setcolor(WHITE);

 	drawTriangle(x1, y1, x2, y2, x3, y3);

    int choice;
    printf("Choose transformation:\n");
    printf("1. Reflect over y = x\n");
    printf("2. Reflect over y = mx + c\n");
    scanf("%d", &choice);

    switch (choice) {
       
        case 1: {
            // Reflect over y = x
            reflectYEqualsX(&x1, &y1);
            reflectYEqualsX(&x2, &y2);
            reflectYEqualsX(&x3, &y3);

            break;
        }
        case 2: {
            // Reflect over y = mx + c
            float m, c;
            printf("Enter slope (m) and intercept (c) for y = mx + c: ");
            scanf("%f %f", &m, &c);
            reflectYEqualsMXPlusC(&x1, &y1, m, c);
            reflectYEqualsMXPlusC(&x2, &y2, m, c);
            reflectYEqualsMXPlusC(&x3, &y3, m, c);

            break;
        }
        
        default: 
            printf("Invalid choice\n");
            closegraph();
            return 1;
    }

    // Draw the transformed triangle
    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
