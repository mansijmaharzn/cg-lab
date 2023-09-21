#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void Draw(int x, int y, int xc, int yc){
	putpixel(x+xc,y+yc,2);
	putpixel(y+xc,x+yc,2);
	putpixel(-y+xc,x+yc,2);
	putpixel(-x+xc,y+yc,2);
	putpixel(x+xc,-y+yc,2);
	putpixel(y+xc,-x+yc,2);
	putpixel(-y+xc,-x+yc,2);
	putpixel(-x+xc,-y+yc,2);
	}
	int main(){
		int x, y, xc, yc, r;
		int p;
		int gdriver = DETECT, gmode;
		initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
		printf("Enter radius::");
		scanf("%d", &r);
		printf("Enter the value of xc and yc::");
		scanf("%d %d", &xc, &yc );
		x=0;
		y=r;
		p=1-r;
		
		while(x<y){
			if(p<0){x++;
			p=p+2*x+1;
			}
			
			else{
				x++;
				y--;
				p=p+2*x+1-2*y;
			}
				Draw(x,y,xc,yc);
				
		}
		getch();
		closegraph();
		return 0;
}
		
			
		
	
	
	
