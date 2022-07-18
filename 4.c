#include<GL/glut.h>
#include<stdio.h>

float v[8][3] = {{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}};

float theta[] = {0.0,0.0,0.0};
int axis = 2;

float viewer[3] = {0,0,5};

void spincube()
{
	theta[axis]+=1;
	if(theta[axis]>360.0) theta[axis]-=360.0;
	glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y){
	if(key=='x') viewer[0]-=1;
	if(key=='X') viewer[0]+=1;
	if(key=='y') viewer[1]-=1;
	if(key=='Y') viewer[1]+=1;
	if(key=='z') viewer[2]-=1;
	if(key=='Z') viewer[2]+=1;
	display();
}
	
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		axis=0;
	}
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN){
		axis=1;
	}
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		axis=2;
	}
	spincube();
}

void polygon(float a[3],float b[3],float c[3],float d[3])
{
	glBegin(GL_POLYGON);
	glVertex3f(a[0],a[1],a[2]);
	glVertex3f(b[0],b[1],b[2]);
	glVertex3f(c[0],c[1],c[2]);
	glVertex3f(d[0],d[1],d[2]);
	glEnd();
}


void colorcube()
{
	glColor3f(0,1,0);
	polygon(v[1],v[2],v[3],v[0]);
	glColor3f(1,0,0);
	polygon(v[2],v[6],v[7],v[3]);
	glColor3f(0,0,1);
	polygon(v[5],v[6],v[7],v[4]);
	glColor3f(1,1,0);
	polygon(v[1],v[5],v[4],v[0]);
	glColor3f(0,1,1);
	polygon(v[1],v[5],v[6],v[2]);
	glColor3f(1,0,1);
	polygon(v[0],v[4],v[7],v[3]);
}

void display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	colorcube();
	glutSwapBuffers();
	glFlush();
}

void Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2,2,-2,2,2,20);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);

	glutCreateWindow("4.CUBE ROTATION");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	//glutIdleFunc(spincube);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
