#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float triangle[3][3] = {{200,250,300},{200,300,200},{1,1,1}};
float angle;
float h,k;
int flag = 1;

float rot_mat[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
float result[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

multiply()
{
	for(int i = 0;i<3;i++)
	{
		for(int j = 0;j<3;j++)
		{
			result[i][j] =0;
			for(int k = 0;k<3;k++)
			{
				result[i][j]+=rot_mat[i][k]*triangle[k][j];
			}
		}
	}
			 
}

rotate(float h,float k)
{
	float m = h*(1-cos(angle))+k*(sin(angle));
	float n = k*(1-cos(angle))-h*(sin(angle));
	
	rot_mat[0][0] = cos(angle);
	rot_mat[0][1] = -sin(angle);
	rot_mat[0][2] = m;
	rot_mat[1][0] = sin(angle);
	rot_mat[1][1] = cos(angle);
	rot_mat[1][2] = n;
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
	multiply();
}

void drawTriangle(float a[3][3])
{
	glBegin(GL_TRIANGLES);
	glVertex3f(a[0][0],a[1][0],a[2][0]);
	glVertex3f(a[0][1],a[1][1],a[2][1]);
	glVertex3f(a[0][2],a[1][2],a[2][2]);
	glEnd();
}

void display()
{
	glClearColor(0.5,0.5,1,0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==1)
	{
		glColor3f(0,1,1);
		drawTriangle(triangle);
	}
	if(flag==2)
	{
		glColor3f(1,0.5,1);
		rotate(0,0);
		drawTriangle(result);
	}
	if(flag==3)
	{
		glColor3f(0.5,0,1);
		rotate(h,k);
		drawTriangle(result);
	}
	glFlush();
}

void menu(int id)
{
	if(id == 1)
	{
		flag = 1;
	}
	if(id == 2)
	{
		flag = 2;
	}
	if(id == 3)
	{
		flag = 3;
	}
	display();
}

void Init()
{
	gluOrtho2D(0,500,0,500);
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	printf("Enter the fixed point: ");
	scanf("%f %f",&h,&k);
	printf("Enter the angle: ");
	scanf("%f",&angle);
	angle = (angle*3.14)/180;
	glutCreateWindow("2.Rotation Of Triangle");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Original Triangle",1);
	glutAddMenuEntry("Rotation About Origin",2);
	glutAddMenuEntry("Rotation about FixedPoint",3);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutMainLoop();
}
