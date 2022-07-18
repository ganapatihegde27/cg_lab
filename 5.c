#include <GL/glut.h>
#include <stdio.h>

int left=2,right=8,bottom=1, top=4;
float xmin=50, ymin=50, xmax=100,ymax=100;
int code0,code1,codeout;

int compute(int x,int y){
	int code=0;
	if(x<xmin){
		code|=left;
	}
	if(x>xmax){
		code|=right;
	}
	if(y<ymin){
		code|=bottom;
	}
	if(y>ymax){
		code|=top;
	}
	return code;
}

void Init(){
	gluOrtho2D(0,500,0,500);
}
void cohen(float x0,float y0,float x1,float y1){
	int accept=0,done=0;
	float x,y;
	code0=compute(x0,y0);
	code1=compute(x1,y1);
	do{
		if(!(code0|code1)){
			done=1;
			accept=1;
		}
		else if(code0&code1){
			done=1;
		}
		else{
			codeout=code0?code0:code1;
			
			if(codeout&bottom){
				y=ymin;
				x=x0+(ymin-y0)*((x1-x0)/(y1-y0));
			}
			
			if(codeout&top){
				y=ymax;
				x=x0+(ymax-y0)*((x1-x0)/(y1-y0));
			}
			
			if(codeout&left){
				x=xmin;
				y=y0+(xmin-x0)*((y1-y0)/(x1-x0));
			}
			
			if(codeout&right){
				x=xmax;
				y=y0+(xmax-x0)*((y1-y0)/(x1-x0));
			}
			
			if(codeout==code0){
				x0=x,y0=y;
				code0=compute(x0,y0);
			}
			if(codeout==code1){
				x1=x,y1=y;
				code1=compute(x1,y1);
			}
		}
	}while(!done);
	if(accept){
		glTranslatef(100,0,0);
		glColor3f(1,0,0);
		glBegin(GL_LINE_LOOP);
			glVertex2f(50,50);
			glVertex2f(100,50);
			glVertex2f(100,100);
			glVertex2f(50,100);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(x0,y0);
			glVertex2f(x1,y1);
		glEnd();
	}
}

void display(){
	float x0=60,y0=20,x1=80,y1=120;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(50,50);
		glVertex2f(100,50);
		glVertex2f(100,100);
		glVertex2f(50,100);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(x0,y0);
		glVertex2f(x1,y1);
	glEnd();

	cohen(x0,y0,x1,y1);

	glFlush();		
}

int main(int argc, char**argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("5.cohen");
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}
