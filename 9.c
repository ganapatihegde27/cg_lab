#include<GL/glut.h>
#include<stdio.h>

int flag = 1;
int x1,y1,x2,y2,x3,y3,x4,y4;

void drawPolygon(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glVertex2i(x3,y3);
	glVertex2i(x4,y4);
	glEnd();
}


void Init()
{
	gluOrtho2D(0,500,0,500);
}

void edgedetect(int x1,int y1,int x2,int y2,int *le,int *re)
{
	float mi,x,temp;
	if((y2-y1)<0)
	{
		temp = y1;
		y1=y2;
		y2 = temp;
		temp = x1;
		x1=x2;
		x2 = temp;
		
	}
	if((y2-y1)!=0){
		mi = (x2-x1)/(y2-y1);
	}
	else{
		mi = x2-x1;
	}
	
	x= x1;
	for(int i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i] = (int)x;
		if(x>(float)re[i])
			re[i] = (int)x;
		
		x= x+mi;
	}
}

void drawPixel(int x,int y)
{
	glColor3f(0,0,1);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void scanfill(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	int le[500],re[500];
	int y,i;
	
	for(i = 0;i<500;i++){
		le[i] = 500;
		re[i] = 0;
	}
	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);
	
	for(y=0;y<500;y++){
		for(i=(int)le[y];i<(int)re[y];i++){
			drawPixel(i,y);
		}
	}
}
		
void display()
{
	glClearColor(0.5,0.5,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==1)
	{
		glColor3f(0,1,1);
		drawPolygon(x1,y1,x2,y2,x3,y3,x4,y4);
	}
	if(flag==2)
	{
		glColor3f(0,0,1);
		scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
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
	display();
}

int main(int argc ,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	printf("Enter the points: ");
	scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	
	glutCreateWindow("9.scan-line alogorithm");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("No Color",1);
	glutAddMenuEntry("Scan Fill",2);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutMainLoop();
}
