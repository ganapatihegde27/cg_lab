#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

int id =0,flag=0;
float theta = 0;
int fact(int n)
{
	int i,sum =1;
	for(i=n;i>=1;i--)
	{
		sum*=i;
	}
	return sum;
}

void combination(int n,int c[4])
{
	int i;
	for (i=0;i<=n;i++)
	{
		c[i] = 1;
		c[i] = fact(n)/(fact(i)*fact(n-i));
	}
}

void curve(float cp[4][2])
{
	int k,n=3,c[4];
	float t;
	float x,y;
	combination(n,c);
	glBegin(GL_LINE_STRIP);
	for(t=0;t<1;t+=0.05)
	{
		x=0,y=0;
		for(k=0;k<=3;k++)
		{
			x+=cp[k][0]*c[k]*pow(t,k)*pow(1-t,n-k);
			y+=cp[k][1]*c[k]*pow(t,k)*pow(1-t,n-k);
		}
		glVertex2f(x,y);
	}
	glEnd();
}

void display()
{
	int i;
	float cp[4][2]={{20,100},{30,110},{40,90},{50,100}};
	glClearColor(0.5,0.7,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	if(flag==1)
	{
		cp[1][0]+=sin(theta*3.14/180);
		cp[1][1]+=sin(theta*3.14/180);
		cp[2][0]-=sin(theta*3.14/180);
		cp[2][1]-=sin(theta*3.14/180);
		cp[3][0]-=sin(theta*3.14/180);
		cp[3][1]+=sin(theta*3.14/180);
		theta+=1.5;
	}
	if(id==1)
	{
		glPushMatrix();
			glLineWidth(3.0);
			
			glColor3f(0,0,0);
			glBegin(GL_LINES);
			   glVertex2f(20,100);
			   glVertex2f(20,20);
			glEnd();
			
			glColor3f(1,0.5,0);
			for(i=0;i<10;i++)
			{
				glTranslatef(0,-0.8,0);
				curve(cp);
			}
			
			glColor3f(1,1,1);
			for(i=0;i<10;i++)
			{
				glTranslatef(0,-0.8,0);
				curve(cp);
			}
			
			glColor3f(0,1,0);
			for(i=0;i<10;i++)
			{
				glTranslatef(0,-0.8,0);
				curve(cp);
			}
			
			
		glPopMatrix();
	}
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();	
}
void menu(int number)
{
	if(number==1)
		id=1;
	if(number==2)
		flag=1;
	if(number==3)
		flag=0;
	
	display();
}

void Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,200,0,200);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

	glutCreateWindow("Flag-beizer curve");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	
	glutCreateMenu(menu);
	glutAddMenuEntry("Flag",1);
	glutAddMenuEntry("Start Animation",2);
	glutAddMenuEntry("Stop Animation",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();
	return 0;
}






			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
