#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float a[3][2],t[2][2],r[10][2],o,d,x00,y00,x01,y01,x02,y02;
void init()
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-300.0,300.0,-300.0,300.0);
}
void draw()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(x00,y00);
glVertex2f(x01,y01);
glVertex2f(x02,y02);
glEnd();
glFlush();
}
void input()
{
printf(" Enter the Coordinates of the Triangle: ");
printf(" x1_y1 ");
scanf("%f%f", &x00,&y00);
printf(" x2_y2 ");
scanf("%f%f", &x01,&y01);
printf(" x3_y3 ");
scanf("%f%f", &x02,&y02);
a[0][0]=x00;
a[0][1]=y00;
a[1][0]=x01;
a[1][1]=y01;
a[2][0]=x02;
a[2][1]=y02;
draw();
}
void mul()
{
int i,j,p;
for(i=0;i<3;i++)
{for(j=0;j<2;j++)
{
r[i][j]=0;
for(p=0;p<2;p++)
{
r[i][j]=r[i][j]+a[i][p]*t[p][j];
}
}
}
x00=r[0][0];
y00=r[0][1];
x01=r[1][0];
y01=r[1][1];
x02=r[2][0];
y02=r[2][1];
}
void sel()
{
int ch,ch1,para;
while(1>0)
{
printf("MENU\n1.Rotation\n2.Reflection\n3.Scaling\n4.Shearing\n5.Translation\n");
printf("Choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the Rotation Degree");
scanf("%f",&o);
d=o*(3.14/180);
t[0][0]=cos(d);
t[0][1]=sin(d);
t[1][0]=-sin(d);
t[1][1]=cos(d);
mul();
draw();
break;
case 2:
printf(" Reflection about 1.x-Axis 2.y-Axis ");
scanf("%d",&ch1);
if(ch1==1)
{
t[0][0]=1;
t[0][1]=0;
t[1][0]=0;
t[1][1]=-1;
}
else if(ch1==2)
{
t[0][0]=-1;
t[0][1]=0;
t[1][0]=0;
t[1][1]=1;
}else
{
printf(" Wrong Option ");
}
mul();
draw();
break;
case 3:
printf(" Uniform Scaling ");
printf(" Enter the Parameter: ");
scanf("%d",&para);
if(para>1)
{
printf(" Expansion ");
}
else
{
printf(" Compression ");
}
t[0][0]=para;
t[0][1]=0;
t[1][0]=0;
t[1][1]=para;
mul();
draw();
break;
case 4:
printf(" Shearing ");
printf(" Enter the Shear Factor: ");
scanf("%d",&para);
x02+=para;
y02+=para;
draw();
break;
case 5:
printf(" Translation ");
printf(" Enter the Translation Degree: ");
scanf("%d",&para);
x00+=para;
y00+=para;
x01+=para;
y01+=para;
x02+=para;
y02+=para;
draw();
break;
case 6:
exit(0);
}
}}
void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE||GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(400,300);
glutCreateWindow("2DTRANSFORMATION");
init();
input();
sel();
glutDisplayFunc(draw);
glutMainLoop();}
