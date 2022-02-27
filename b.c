#include<stdlib.h>
#include<GL/glut.h>
float ballX = -0.8f;
float ballY = 0.5f;
float ballZ = -1.0f;
static int flag=1;
static int flagger=1;
void drawBall(void) {
glColor3f(0.0, 1.0, 1.0);
glTranslatef(ballX,ballY,ballZ);
glutSolidSphere (0.1, 100, 10); //Objects
}
void keyPress(int key, int x, int y)
{
if(key==GLUT_KEY_UP)
ballY += 0.05f;
if(key==GLUT_KEY_DOWN)
ballY -= 0.05f;
if(key==GLUT_KEY_LEFT)
ballX -= 0.05f;
if(key==GLUT_KEY_RIGHT)
ballX += 0.05f;
glutPostRedisplay();
}
void initRendering()
{
glEnable(GL_DEPTH_TEST);
}
void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();//Identity Matrix
drawBall();
glutSwapBuffers();
}
float rt=0.5;
float i=0.006f;
void updater(int value){
if(flagger)
{
ballX += i;
if(ballX>0.9)
{
i -= 0.001f;flagger=0;
}
}
if (!flagger)
{
ballX -= i;
if(ballX<-0.9)
{
i -= 0.001f;
flagger=1;
}
}
glutPostRedisplay();
glutTimerFunc(1, updater, 5000);
}
void update(int value) {
if(flag)
{
ballY += 0.01f;
if(ballY>rt)
{
flag=0;
}
}
rt=rt-0.001;
if (!flag)
{
ballY -= 0.01f;
if(ballY<-0.5)
{
flag=1;
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
glutDisplayFunc(drawScene);
glutSpecialFunc(keyPress);
glutTimerFunc(300, update, 5000);
glutTimerFunc(300, updater, 5000);
glutMainLoop();
return(0);
}
