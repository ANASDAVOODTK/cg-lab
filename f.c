#include<stdlib.h>
#include<GL/glut.h>
float kiteX = -0.8f;
float kiteY = -0.5f;
float kiteZ = -1.0f;
static int flag=1;
static int flagger=1;
void drawKite(void) {
glColor3f(0.0, 1.0, 1.0);
glTranslatef(kiteX,kiteY,kiteZ);
glBegin(GL_POLYGON);
glVertex2f(0.0,-0.3);
glVertex2f(-0.3,0.0);
glVertex2f(0.0,0.3);
glVertex2f(0.3,0.0);
glEnd();
glFlush();
glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2f(-0.3,0.0);
glVertex2f(-0.3,-0.5);
glVertex2f(0.3,0.0);
glVertex2f(0.3,-0.5);
glColor3f(1.0,1.0,0.0);
glVertex2f(0.0,-0.3);
glVertex2f(0.0,-5.0);
glEnd();
glFlush();
}
void keyPress(int key, int x, int y)
{
if(key==GLUT_KEY_UP)
kiteY += 0.05f;
if(key==GLUT_KEY_DOWN)
kiteY -= 0.05f;
if(key==GLUT_KEY_LEFT)
kiteX -= 0.05f;
if(key==GLUT_KEY_RIGHT)
kiteX += 0.05f;
glutPostRedisplay();
}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();//Identity Matrix
drawKite();
glutSwapBuffers();
}
float rt=0.5;
float x=0.9;
void updater(int value){
if(flag==0)
x=0.4;
if(flagger)
{
kiteX += 0.002f;
if(kiteX>x)
{
flagger=0;
}
}
if (!flagger)
{
kiteX -= 0.002f;
if(kiteX<-x)
{
flagger=1;
}
}
glutPostRedisplay();
glutTimerFunc(1, updater, 5000);
}
void update(int value)
{
if(flag)
{
kiteY += 0.0005f;
if(kiteY>rt)
{
flag=0;
}
}
glutPostRedisplay();
glutTimerFunc(1, update, 5000);
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(400,400);
glutCreateWindow("Ball Bounce");
initRendering();
glutDisplayFunc(drawScene);glutSpecialFunc(keyPress);
glutTimerFunc(30, update, 5000);
glutTimerFunc(30, updater, 5000);
glutMainLoop();
return(0);
}
