#include<stdio.h>
#include<GL/glut.h>
float r,x,y;
void data()
{
printf("Enter the radius(r), center of circle(x,y): ");
scanf("%f %f %f",&r,&x,&y);
}
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-200.0,200.0,-150.0,150.0);
}
void circle()
{
float x0,y0,p0,pk,xk,yk,x1,y1;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2f(x,y);
//1st positon on the circumferance
x0=0;
y0=r;
//decision parameter
p0=1-r;
pk=p0;
xk=x0;
yk=y0;
while(xk<=yk)
{
if(pk<0)
{
xk+=1;
pk=pk+2*xk+2;
}
else
{
xk+=1;
yk-=1;
pk=pk+2*xk+3-2*yk-1;
}
x1=x+xk;y1=y+yk;
glVertex2f(x1,y1);
glVertex2f(y1,x1);
glVertex2f(x-xk,y-yk);
glVertex2f(y-yk,x-xk);glVertex2f(x-xk,y1);
glVertex2f(y1,x-xk);
glVertex2f(x1,y-yk);
glVertex2f(y-yk,x1);
glVertex2f(x,y+r);
glVertex2f(x,y-r);
glVertex2f(x+r,y);
glVertex2f(x-r,y);
}
glEnd();
glFlush();
}
void main(int argc,char **argv)
{
data();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(400,300);
glutCreateWindow("Circle");
init();
glutDisplayFunc(circle);
glutMainLoop();
}
Out
