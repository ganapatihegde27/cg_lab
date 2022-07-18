#include<GL/glut.h>
#include<stdio.h>
int n;
float v[4][3] = {{-1,-1,0},{0,1,0},{1,-1,0},{0,0,1}};

void triangle(float a[3],float b[3],float c[3])
{
	glBegin(GL_TRIANGLES);
	glVertex3f(a[0],a[1],a[2]);
	glVertex3f(b[0],b[1],b[2]);
	glVertex3f(c[0],c[1],c[2]);
	glEnd();
}

void d_triangle(float a[3],float b[3],float c[3],int n)
{
	float x1[3],x2[3],x3[3];
	if(n>=1)
	{
		for(int i=0;i<3;i++)
		{
			x1[i]=(a[i]+c[i])/2;
			x2[i]=(a[i]+b[i])/2;
			x3[i]=(b[i]+c[i])/2;
		}
		d_triangle(a,x1,x2,n-1);
		d_triangle(b,x2,x3,n-1);
		d_triangle(c,x1,x3,n-1);
	}
	else
	{
		triangle(a,b,c);
	}
}

void tetrahedron()
{
	glColor3f(1,0,0);
	d_triangle(v[0],v[1],v[2],n);
	glColor3f(0,1,0);
	d_triangle(v[0],v[1],v[3],n);
	glColor3f(0,0,1);
	d_triangle(v[1],v[2],v[3],n);
	glColor3f(1,1,0);
	d_triangle(v[0],v[2],v[3],n);
}

void display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	tetrahedron();
	glFlush();
}

void Init()
{
	glOrtho(-1.1,1.1,-1.1,1.1,-1.1,1.1);
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
	printf("Enter the value of n: ");
	scanf("%d",&n);
	glutCreateWindow("7.tetrahedron");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
