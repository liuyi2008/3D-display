#include<stdio.h>
#include<iostream>
#include <vector>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>

void init(int argc, char** argv)
{
	glutInit(&argc, argv);  //I��ʼ�� GLUT.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);  //������ʾģʽ�����������ʹ��RGBģ��
	glutInitWindowPosition(50, 100);  //���ô��ڵĶ��������λ��
	glutInitWindowSize(400, 300);  //���ô��ڵĸ߶ȺͿ��
	glutCreateWindow("draw cell structure");

	glShadeModel(GL_SMOOTH);
	glClearColor(1.0, 1.0, 1.0, 1.0); //���ڱ�����ɫΪ��ɫ
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 600, 0, 450);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
	glBegin(GL_LINES);

	//glBegin(GL_LINES);
	//for (int i = 1; i < tripoint.size(); i+=2)
	//{

	//	glColor3f(1.0f, 0.0f, 0.0f); //���Ǻ�ɫ��
	//	glVertex2f(tripoint[i-1].x, tripoint[i-1].y);
	//	glVertex2f(tripoint[i].x, tripoint[i].y);
	//	//printf("i=%d,x=%f,y=%f\n",i , tripoint[i].x, tripoint[i].y);		

	//}
	//glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0); glVertex2f(200, 0);
	glVertex2f(200, 0); glVertex2f(200, 200);
	glVertex2f(200, 200); glVertex2f(0, 200);
	glVertex2f(0, 200); glVertex2f(0, 0);
	glEnd();

	//glBegin(GL_LINES);
	//for (int i = 0; i < new_tripoint.size(); i++)
	//{

	//	glColor3f(1.0f, 0.0f, 0.0f); //���Ǻ�ɫ��
	//	glVertex2f(new_tripoint[i].x, new_tripoint[i].y);
	//	//printf("i=%d,x=%f,y=%f\n",i , tripoint[i].x, tripoint[i].y);		

	//}
	//glEnd();

	//glBegin(GL_LINE_LOOP);
	//for (int i = 0; i < polypoint.size(); i++)
	//{

	//	glColor3f(0.0f, 0.0f, 1.0f); //���Ǻ�ɫ��
	//	glVertex2f(polypoint[i].x, polypoint[i].y);
	//	//printf("i=%d,x=%f,y=%f\n",i , tripoint[i].x, tripoint[i].y);		

	//}
	//glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	init(argc, argv);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}