#include<GL/glut.h>
#include<stdio.h>
int rx,ry,xc,yc,x,y;
void Input()
{
printf("\n enter the centre of the ellipse:");
scanf("%d%d",&xc,&yc);
printf("\n enter the radius of the ellipse:");
scanf("%d%d",&rx,&ry);
}
void Init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0 , 640 , 0 , 480);
}
void Ellipse()
{
int p1k,p2k;
glClear(GL_COLOR_BUFFER_BIT);
x=0;
y=ry;
int rysqr=(ry*ry);
int rxsqr=(rx*rx);
p1k=((rysqr)-(rxsqr*ry)+((1/4)*rxsqr));
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
do
{
if(p1k<0)
{
x=x+1;
p1k=(p1k+(2*rysqr*x)+rysqr);
}
else
{
y--; x=x+1;
p1k=(p1k+(2*rysqr*x)+rysqr-(2*rxsqr*y));
}
glVertex2f(xc+x,yc+y);
glVertex2f(xc+x,yc-y);
glVertex2f(xc-x,yc-y);
glVertex2f(xc-x,yc+y);
} while((2*rysqr*x)<(2*rxsqr*y));
glEnd();
glFlush();p2k=(rysqr*((x+(1/2))*(x+(1/2)))+(rxsqr*((y-1)*(y-1)))-(rxsqr*rysqr));
do
{
if(p2k>0)
{
y=y-1;
p2k=(p2k-(2*rxsqr*y)+rxsqr);
}
else
{
x=x+1;
y=y-1;
p2k=(p2k+(2*rysqr*x)-(2*rxsqr*y)+rxsqr);
}
glBegin(GL_POINTS);
glVertex2f(xc+x,yc+y);
glVertex2f(xc+x,yc-y);
glVertex2f(xc-x,yc-y);
glVertex2f(xc-x,yc+y);
}while(y>=0);
glEnd();
glFlush();
}
void main(int argc,char **argv)
{
Input();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
glutCreateWindow("ELLIPSE");
Init();
Ellipse();
glutMainLoop();
}
