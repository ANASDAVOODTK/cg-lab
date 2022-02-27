#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float x, y,r;
void circle();
void data()
{
printf("\nEnter center and radius: ");
scanf("%f%f%f",&x,&y,&r);
}
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,800.0,0.0,800.0);
}
void circle()
{
float x0,y0,xk,yk,p0,pk,x1,y1;
int count=0,temp;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
temp=x;
int i;
for(i=0;i<5;i++)
{
if(count==0)
glColor3f(0.0,0.0,1.0);
if(count==1)
glColor3f(0.0,0.0,0.0);
if(count==2)
glColor3f(1.0,0.0,0.0);
if(count==3)
glColor3f(1.0,1.0,0.0);
if(count==4)
glColor3f(0.0,1.0,0.0);
x0=0;
y0=r;
p0=1-r;
xk=x0;
yk=y0;
pk=p0;
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
glVertex2f(x+yk,y+xk);
glVertex2f(x-xk,y+yk);
glVertex2f(x-yk,y+xk);
glVertex2f(x+xk,y-yk);
glVertex2f(x+yk,y-xk);
glVertex2f(x-xk,y-yk);
glVertex2f(x-yk,y-xk);
glVertex2f(x,y+r);
glVertex2f(x,y-r);
glVertex2f(x+r,y);
glVertex2f(x-r,y);
}
if(i<2)
{
x=x+2*r+(r/3);
}
else if(i==2)
{
x=temp+(2*r+(r/3))/2;
y=y-r+(((2*r+(r/3))/2)*tan(60));
}
else if(i==3)
{
x=x+2*r+(r/4);
}
++count;
}
glEnd();
glFlush();
}
void main(int argv, char **argc)
{
data();
glutInit(&argv,argc);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(400,400);
glutCreateWindow("Olympic Ring");
init();
glutDisplayFunc(circle);
glutMainLoop();
}
