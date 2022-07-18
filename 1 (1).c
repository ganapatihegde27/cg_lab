#include<GL/glut.h>
#include<stdio.h>
float x0,y0,x1,y1;
void pixel(float x,float y)
{
	//glColor3f(0,0,1);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void line(float x0,float y0,float x1,float y1)
{
	float dx = abs(x1-x0);
	float dy = abs(y1-y0);
	
	float incrx=1,incry=1;
	if(x0>x1)
	{
		incrx=-1;
	}
	if(y0>y1)
	{
		incry=-1;
	}
	
	if(dx>dy)
	{
		float p= (2*dy)-dx;
		float x=x0,y=y0;
		
		for(int i=0;i<dx;i++)
		{
			x=x+incrx;
			
			if(p<0)
			{
				p=p+(2*dy);
			}
			else
			{
				y=y+incry;
				p=p+(2*dy)-(2*dx);
			}
			pixel(x,y);
			
		}
	}
	else
	{
		float p= (2*dx)-dy;
		float x=x0,y=y0;
		
		for(int i=0;i<dy;i++)
		{
			y=y+incry;
			
			if(p<0)
			{
				p=p+(2*dx);
			}
			else
			{
				x=x+incrx;
				p=p+(2*dx)-(2*dy);
			}
			pixel(x,y);
			
		}
	}
}	
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	
	glColor3f(0,0,1);
	line(100,100,200,180);
	glColor3f(1,0,1);
	line(100,100,200,20);
	glColor3f(0,1,1);
	line(100,100,180,200);
	glFlush();
}

void Init()
{
	gluOrtho2D(0,500,0,500);
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	//printf("enter x0,y0,x1,y1: ");
	//scanf("%f %f %f %f",&x0,&y0,&x1,&y1);
	glutCreateWindow("1.line");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}


			
				
				
				
	
