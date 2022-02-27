#include<GL/glut.h>
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,150.0);
}
void dda()
{
float steps,Xa=0.0,Ya=0.0,Xb=400.0,Yb=300.0;
float Dx=Xb-Xa;
float Dy=Yb-Ya;
float X=Xa,Y=Ya;
float Xinc,Yinc;
int k;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
if(abs(Dx)>abs(Dy))
{
steps=abs(Dx);
}
else
{
steps=abs(Dy);}
Xinc=Dx/steps;
Yinc=Dy/steps;
glVertex2f(X,Y);
for(k=0;k<steps;k++)
{
X+=Xinc;
Y+=Yinc;
k++;
glVertex2f(X,Y);
}
glEnd();
glFlush();
}
void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(400,300);
glutCreateWindow("DDA");
init();
glutDisplayFunc(dda);
glutMainLoop();
}