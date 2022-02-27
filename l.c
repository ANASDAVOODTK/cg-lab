#include<GL/glut.h>
#include<stdio.h>
int lx1,ly1,lx2,ly2,bxmin,bymin,bxmax,bymax,rr1,rr2;
void init() {
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-250.0,250.0,-250.0,250.0);
}
int finder(int x, int y,int xmin,int ymin,int xmax, int ymax){
int op=0,oo=0,top=1000,bottom=0100,left=0001,right=0010;
if (y > ymax)
op = op+1000;
else if (y < ymin)
op = op+100;
if (x > xmax)
op =op+ 10;
else if (x < xmin)
op = op+1;
return op;
}
void redraw(){
float x1=lx1,a,b,c,d,x2=lx2,y1=ly1,y2=ly2,m,x,yr1,yrr1,xrr1,xr1,y,xr2,yr2,xrr2,yrr2,k,l;
m=((y2-y1)/(x2-x1));
yr1=y1+(m*(bxmin-x1));
yrr1=y1+(m*(bxmax-x1));
xr1=x1+((bymin-y1)/m);
xrr1=x1+((bymax-y1)/m);
yr2=y2+(m*(bxmin-x2));
yrr2=y2+(m*(bxmax-x2));
xr2=x2+((bymin-y2)/m);
xrr2=x2+((bymax-y2)/m);k=((yr2-yr1)/(xr2-xr1));
l=((yrr2-yrr1)/(xrr2-xrr1));
{
switch(rr1){
case 0:a=lx1;b=ly1;break;
case 1:a=bxmin;b=yr1;break;
case 10:a=bxmax;b=yrr1;break;
case 1000:a=xrr1;b=bymax;break;
case 100:a=xr1;b=bymin;break;
case 1001:a=xrr1;b=yr1;if(xr1<bxmin) a=bxmin; if(yr1<bymin) b=bymin;break;
case 1010:a=xrr1;b=yrr1;if(xr1<bxmin) a=bxmin; if(yr1<bymin) b=bymin;break;
case 101:a=yr1;b=yr1;if(xr1<bxmin) a=bxmin; if(yr1<bymin) b=bymin;break;case 
110:a=yrr1;b=xr1;if(xr1<bxmin) a=bxmin; if(yr1<bymin) b=bymin;break;
default:printf("error swtich");
}
switch(rr2){
case 0:c=lx2;d=ly2;break;
case 1:c=bxmin;d=yr2;break;
case 10:c=bxmax;d=yrr2;break;
case 1000:c=xrr2;d=bymax;break;
case 100:c=xr2;d=bymin;break;
case 1001:c=xrr2;d=yr2;if(xrr2>bxmax) c=bxmax; if(yrr2>bymax) d=bymax;break;
case 1010:c=xrr2;d=yrr2;if(xrr2>bxmax) c=bxmax; if(yrr2>bymax) d=bymax;break;
case 101:c=yr2;d=yr2;if(xrr2>bxmax) c=bxmax; if(yrr2>bymax) d=bymax;break;
case 110:c=yrr2;d=xr2;if(xrr2>bxmax) c=bxmax; if(yrr2>bymax) d=bymax;break;
default:printf("error swtich");
}
}
glColor3f(1.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2i(a,b);
glVertex2i(c,d);
glEnd();
glFlush();
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(bxmin,bymin);
glVertex2i(bxmin,bymax);
glVertex2i(bxmax,bymax);
glVertex2i(bxmax,bymin);
glEnd();
glFlush();
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINES);
glVertex2i(lx1,ly1);
glVertex2i(a,b);
glVertex2i(lx2,ly2);
glVertex2i(c,d);
glEnd();
glFlush();
}
void equality(){
int r1=0,r2=0,t1,t2,e=0,t=1;
r1=finder(lx1,ly1,bxmin,bymin,bxmax,bymax);
r2=finder(lx2,ly2,bxmin,bymin,bxmax,bymax);
rr1=r1;rr2=r2;
printf("\nLine is :");
do{
e=e+1;
t1=r1%10;
t2=r2%10;
if(t1==t2&&t1==1&&t2==1){
switch(e){
case 1:printf("Left ");t=0;break;
case 2:printf("Right ");t=0;break;case 3:printf("Bottom ");t=0;break;
case 4:printf("Top ");t=0;break;
deafult:t=1;break;
}
}
r1=r1/10;
r2=r2/10;
}while(e<=4);
if(t==1)
{
printf("Inside %d\t%d\nEnter any key to continue",rr1,rr2);
int a;
scanf("%d",&a);
redraw();
}
else
printf("| Outside\n");
}
void draw(){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
glVertex2i(lx1,ly1);
glVertex2i(lx2,ly2);
glEnd();
glFlush();
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(bxmin,bymin);
glVertex2i(bxmin,bymax);
glVertex2i(bxmax,bymax);
glVertex2i(bxmax,bymin);
glEnd();
glFlush();
}
void reader(){
printf("Enter line vertices:");
scanf("%d%d%d%d",&lx1,&ly1,&lx2,&ly2);
bxmin=50;
bymin=50;
bxmax=150;
bymax=150;
}
void main(int argc, char ** argv)
{
reader();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200,100);
glutInitWindowSize(500,500);
glutCreateWindow("Line Clipping");
init();
glClear(GL_COLOR_BUFFER_BIT);
draw();glutDisplayFunc(equality);
glutMainLoop();
}
