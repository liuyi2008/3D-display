#include<stdio.h>
#include<iostream>
#include <vector>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>

void init(int argc, char** argv)
{
	glutInit(&argc, argv);  //I初始化 GLUT.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);  //设置显示模式：单个缓存和使用RGB模型
	glutInitWindowPosition(50, 100);  //设置窗口的顶部和左边位置
	glutInitWindowSize(400, 300);  //设置窗口的高度和宽度
	glutCreateWindow("draw cell structure");

	glShadeModel(GL_SMOOTH);
	glClearColor(1.0, 1.0, 1.0, 1.0); //窗口背景颜色为白色
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

	//	glColor3f(1.0f, 0.0f, 0.0f); //线是红色的
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

	//	glColor3f(1.0f, 0.0f, 0.0f); //线是红色的
	//	glVertex2f(new_tripoint[i].x, new_tripoint[i].y);
	//	//printf("i=%d,x=%f,y=%f\n",i , tripoint[i].x, tripoint[i].y);		

	//}
	//glEnd();

	//glBegin(GL_LINE_LOOP);
	//for (int i = 0; i < polypoint.size(); i++)
	//{

	//	glColor3f(0.0f, 0.0f, 1.0f); //线是红色的
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