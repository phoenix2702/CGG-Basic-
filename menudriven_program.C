#include<graphics.h>  
#include<conio.h>  
#include<stdio.h>  
int dda(int x0, int x1, int y0, int y1 )  
{  int gd = DETECT, gm;
  char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
 initgraph(&gd, &gm, data);
     
    float x, y,dx,dy,steps;  
     
    int i;
    setbkcolor(WHITE);   
    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  
    if(dx>=dy)  
           {  
        steps = dx;  
    }  
    else  
           {  
        steps = dy;  
    }  
    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;  
    i = 1;  
    while(i<= steps)  
    {  
        putpixel(x, y, RED);  
        x += dx;  
        y += dy;  
        i=i+1;  
    } 
     getch();  
    closegraph();  
    return 0;  
   
}
    
int bersenham(int x1,int y1,int x2,int y2)
    {

       int gd = DETECT, gm;
    int dx, dy, p, x, y;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
 initgraph(&gd, &gm, data);
  dx = x2 - x1;
  dy = y2 - y1;

  x = x1;
  y = y1;

  p = 2 * dy - dx;

  while (x < x2) {
    if (p >= 0) {
      putpixel(x, y, WHITE);
      y = y + 1;
      p = p + 2 * dy - 2 * dx;
    } else {
      putpixel(x, y, WHITE);
      p = p + 2 * dy;
    }
    x = x + 1;
  } 
  getch();  
    closegraph();  
    return 0;
    }

int objectD(int x, int y, int r)
{
  int gd = DETECT, gm;
  char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
 initgraph(&gd, &gm, data);
    int x0 = 0;
    int y0 = r;
    int d = 3 - 2 * r;

    while (x0 <= y0) {
        putpixel(x + x0, y + y0, WHITE);
        putpixel(x + x0, y - y0, WHITE);
        putpixel(x - x0, y + y0, WHITE);
        putpixel(x - x0, y - y0, WHITE);
        putpixel(x + y0, y + x0, WHITE);
        putpixel(x + y0, y - x0, WHITE);
        putpixel(x - y0, y + x0, WHITE);
        putpixel(x - y0, y - x0, WHITE);

        if (d < 0) {
            d += 4 * x0 + 6;
        } else {
            d += 4 * (x0 - y0) + 10;
            y0--;
        }
        x0++;
    }
    getch();  
    closegraph();  
    return 0; 
}

int drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    float p = 5/4 - r;

    // Initiate graphics mode
    int gd = DETECT, gm;
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file
initgraph(&gd, &gm, data);
    

    // Draw initial circle points
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc + x, yc - y, WHITE);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2*x + 1;
        }
        else {
            y--;
            p += 2*(x-y) + 1;
        }
        // Plot the points of the circle
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
    }

    // Close graphics mode
    getch();
    closegraph();
}
  

int main()
{
    int n;
    printf("1.For dda\n2.for berseham\n3.for object");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    int x0,x1,y0,y1;
    printf("Enter coordinates:");
    printf("Enter x0:");
    scanf("%d",&x0);
    printf("Enter x1:");
    scanf("%d",&x1);
    printf("Enter y0:");
    scanf("%d",&y0);
    printf("Enter y1:");
    scanf("%d",&y1);
    dda(x0,x1,y0,y1);
        break;
    
    case 2:
    int x2,y2;
    printf("Enter coordinates:");
    printf("Enter x1:");
    scanf("%d",&x1);
    printf("Enter y1:");
    scanf("%d",&y1);
    printf("Enter x2:");
    scanf("%d",&x2);
    printf("Enter y2:");
    scanf("%d",&y2);  
    bersenham(x1,y1,x2,y2);
        break;
    case 3:
    int d;
    printf("1.dda\n2.bersenham");
    scanf("%d",&d);
    switch (d)
    {
    case 1:
      objectD(250,250,100);
      break;
    case 2:
    drawCircle(200,100,100) ; 
    
    default:
      break;
    }
    
    default:
    printf("error");
    }
    
}
 