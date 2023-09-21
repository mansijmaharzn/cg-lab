// By: Sachana
#include <graphics.h>
#include <math.h>



void shear(float *x, float *y, float shearFactorX, float shearFactorY) {
    float temp_x = *x;
    *x = temp_x + shearFactorX * (*y);
    *y = shearFactorY * temp_x + (*y);
}

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    line(centerX + x1, centerY - y1, centerX + x2, centerY - y2);
    line(centerX + x2, centerY - y2, centerX + x3, centerY - y3);
    line(centerX + x3, centerY - y3, centerX + x4, centerY - y4);
    line(centerX + x4, centerY - y4, centerX + x1, centerY - y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float x1, y1, x2, y2, x3, y3, x4, y4;

    printf("Enter coordinates of the rectangle:\n");
    scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    setcolor(WHITE);

 	drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

    int choice;
    printf("Choose transformation:\n");
    printf("1. Shear in X direction\n");
    printf("2. Shear in Y direction\n");
    printf("3. Shear in both directions\n");
    scanf("%d", &choice);

    switch (choice) {
       
        
        case 1: {
            // Shearing in X direction
            float shearFactorX = 0.5;
            shear(&x1, &y1, shearFactorX, 0);
            shear(&x2, &y2, shearFactorX, 0);
            shear(&x3, &y3, shearFactorX, 0);
            shear(&x4, &y4, shearFactorX, 0);

            break;
        }
        case 2: {
            // Shearing in Y direction
            float shearFactorY = 0.5;
            shear(&x1, &y1, 0, shearFactorY);
            shear(&x2, &y2, 0, shearFactorY);
            shear(&x3, &y3, 0, shearFactorY);
            shear(&x4, &y4, 0, shearFactorY);
            break;
        }
        case 3: {
            // Shearing in both directions
            float shearFactorX = 0.5;
            float shearFactorY = 0.5;
            shear(&x1, &y1, shearFactorX, shearFactorY);
            shear(&x2, &y2, shearFactorX, shearFactorY);
            shear(&x3, &y3, shearFactorX, shearFactorY);
            shear(&x4, &y4, shearFactorX, shearFactorY);


            break;
        }
        default:
            printf("Invalid choice\n");
            closegraph();
            return 1;
    }

    // Draw the transformed rectangle
    setcolor(WHITE);
    drawRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

    getch();
    closegraph();
    return 0;
}
