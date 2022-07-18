#include<GL/glut.h>
void wall(double thickness)
{
glPushMatrix();
glTranslated(0.5,0,0.5);
glScaled(1.0,thickness,1.0);
glutSolidCube(1.0);
glPopMatrix();
}

void tableleg(double thick,double len)
{
glPushMatrix();
glTranslated(0,len/2,0);
glScaled(thick,len,thick);
glutSolidCube(1.0);
glPopMatrix();
}

void table(double topwid,double topthick,double legthick,double leglen)
{
glPushMatrix();
glTranslated(0,leglen,0);
glScaled(topwid,topthick,topwid);
glutSolidCube(1.0);
glPopMatrix();

double dist=0.3;

glPushMatrix();
glTranslated(dist,0,dist);
tableleg(legthick,leglen);
glTranslated(0,0,-2*dist);
tableleg(legthick,leglen);
glTranslated(-2*dist,0,2*dist);
tableleg(legthick,leglen);
glTranslated(0,0,-2*dist);
tableleg(legthick,leglen);
glPopMatrix();
}




void display()
{
	GLfloat mat_amb[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diff[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_spec[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_shine[]={50.0f};
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_amb);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_spec);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shine);
	
	
	GLfloat lightintensity[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat lightposition[]={2.0f,6.0f,3.0f,0.0f};
	
	glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);	
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(2,2,2,0,0,0,0,1,0);
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	glTranslated(0.4,0.4,0.4);
	glutSolidTeapot(0.08);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(0.4,0,0.4);
	table(0.6,0.06,0.06,0.3);
	glPopMatrix();
	
	glPushMatrix();
	glRotated(90,0,0,1);
	wall(0.02);
	glPopMatrix();
	
	glPushMatrix();
	glRotated(-90,1,0,0);
	wall(0.02);
	glPopMatrix();
	
	glPushMatrix();
	glRotated(0,0,1,0);
	wall(0.02);
	glPopMatrix();
	
	glFlush();
}


int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);

	glutCreateWindow("TEA POTON TABLE");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	
	//Init();
	glutDisplayFunc(display);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	
	//glViewPort(0,0,500,500);
	glutMainLoop();
}
