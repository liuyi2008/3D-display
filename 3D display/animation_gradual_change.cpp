#include <gl/glut.h>
#include<math.h>
#include <stdlib.h>//exit
#include <vector>

using std::vector;

struct point {

	int x, y;

}p;

vector<point>polypoint;

float y = 0.0f;//基准坐标

float y2;//基准坐标

float dy = 0.0006f;//变换量

float a = 1.5f;//阈值

int process = 1;//控制过程，1：状态1变化到2，2：状态2变回到1


void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-3.0, 15.0, -15.0, 3.0); //  窗口（画纸），设置显示的范围是X:-5.0~5.0, Y:-5.0~5.0  比例和视区一样

	glMatrixMode(GL_MODELVIEW);

}

//void Reshape(int w, int h)
//{
//
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //设置视区尺寸
//
//	glMatrixMode(GL_PROJECTION); //指定当前操作投影矩阵堆栈
//
//	glLoadIdentity(); //重置投影矩阵
//
//	//指定透视投影的观察空间
//
//	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
//
//}

void drawTriangle_line() //绘制一个下单上双的三角形，原点是三角形的中心点，这里的y是小三角形边长
{
	//glEnable(GL_LINE_SMOOTH);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP); //下单上双

	glVertex2f(0.0f, -a);//下点

	glVertex2f(-a * sqrt(3) * 0.5, a * 0.5);//左点

	glVertex2f(a*sqrt(3) * 0.5, a * 0.5);//右点

	glEnd();

	glBegin(GL_LINES); //三角形里面的变化线

	glVertex2f(-a * sqrt(3) * 0.5 + y, a * 0.5); glVertex2f(-a * sqrt(3) * 0.5 + 0.5 * y, 0.5 * a - 0.5*sqrt(3)*y);  //丿

	glVertex2f(a * sqrt(3) * 0.5 - y, a * 0.5); glVertex2f(a*sqrt(3) * 0.5 - 0.5 * y, a * 0.5 - 0.5*sqrt(3)*y);  //捺

	glVertex2f(0.0f - 0.5*y, -a+0.5*sqrt(3)*y); glVertex2f(0.0f+0.5*y, -a + 0.5*sqrt(3)*y);  //一

	glEnd();

	glBegin(GL_LINES);//三角形右边，围成的三角形的变化线

	glVertex2f(sqrt(3)*a - y,-a); glVertex2f(sqrt(3)*a - 0.5*y, -a + 0.5*sqrt(3)*y);  //丿

	glVertex2f(0.0f + y, -a); glVertex2f(0.0f+0.5*y, -a + 0.5*sqrt(3)*y);  //捺

	glVertex2f(a*sqrt(3) * 0.5 - 0.5*y, a * 0.5 - 0.5*sqrt(3)*y); glVertex2f(a*sqrt(3) * 0.5 + 0.5*y, a * 0.5 - 0.5*sqrt(3)*y);  //一

	glEnd();

}

void drawTriangle_line2() //绘制一个下双上单的基本单元
{
	//glEnable(GL_LINE_SMOOTH);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP); //下双上单

	glVertex2f(0.0f, 0.5 * a);//上点

	glVertex2f(-a * sqrt(3) * 0.25, -a * 0.25);//左点

	glVertex2f(a*sqrt(3) * 0.25, -a * 0.25);//右点

	glEnd();

	glBegin(GL_LINES); //定点线

	glVertex2f(0.0f - 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2); glVertex2f(0.0f + 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2);//一

	glVertex2f(a*sqrt(3) * 0.25 - y2, -a * 0.25); glVertex2f(a*sqrt(3) * 0.25 - 0.5*y2, -a * 0.25 + 0.5*sqrt(3)*y2); //丿

	glVertex2f(-a * sqrt(3) * 0.25 + y2, -a * 0.25); glVertex2f(-a * sqrt(3) * 0.25 + 0.5* y2, -a * 0.25 + 0.5*sqrt(3)*y2); //捺

	glEnd();

	glBegin(GL_LINES);  //右边空三角形里的线

	glVertex2f(a*sqrt(3) * 0.25-0.5*y2, -a * 0.25+0.5*sqrt(3)*y2); glVertex2f(a*sqrt(3) * 0.25+0.5*y2, -a * 0.25 + 0.5*sqrt(3)*y2);//一

	glVertex2f(0.0f + y2, 0.5 * a); glVertex2f(0.0f+0.5*y2, 0.5 * a-0.5*sqrt(3)*y2); //丿

	glVertex2f(0.5*sqrt(3)*a - y2, 0.5 * a); glVertex2f(0.5*sqrt(3)*a - 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2); //捺

	glEnd();

}

void Display(void) //基本的最大的三角网格
{
	glClear(GL_COLOR_BUFFER_BIT);//清除颜色和深度缓冲区

	for (int i = 0; i < 10; i++) // 画i行,j列
	{
		glLoadIdentity(); //重置模型视图矩阵

		glTranslatef(i % 2 * 0.5 * sqrt(3) * a, i*-1.5 * a, 0.0);  //下一行 ，j%2 是一行右移下一行不动

		drawTriangle_line();

		for (int j = 1; j < 10; j++) //一行画5个（列）
		{
			glTranslatef(sqrt(3) * a, 0.0, 0.0);

			drawTriangle_line();

		}

	}

	glFlush();

	glLoadIdentity();

	//glutSwapBuffers();

}

void Display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//清除颜色和深度缓冲区

	for (int i = 0; i < 15; i++) // 画i行,j列
	{
		glLoadIdentity(); //重置模型视图矩阵

		glTranslatef(i % 2 * 0.25 * sqrt(3) * a, i * -0.75 * a, 0.0);  //下一行 ，i%2 是一行右移下一行不动

		drawTriangle_line2();

		for (int j = 1; j < 15; j++) //一行画5个（列）
		{
			glTranslatef(0.5 * sqrt(3) * a, 0.0, 0.0);

			drawTriangle_line2();

		}

	}

	glFlush();

	glLoadIdentity();

}

void myIdle(void) //在空闲时调用，达到动画效果
{
	if (y < a*sqrt(3) * 0.5)
	{
		y += dy;
		Display();
	}
	else if (y >= a * sqrt(3) * 0.5)
	{
		if (y2 <= a * sqrt(3) * 0.25)
			y2 += dy;

		Display2();

		glClear(GL_COLOR_BUFFER_BIT);//清除颜色和深度缓冲区

	}

}

void mymouse(GLint button, GLint state, GLint wx, GLint wy)

{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

		exit(0);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int x = wx;
		int y = wy;
		p = { x,y };
		polypoint.push_back(p);
	}
}

void ControlPoint()
{

	glPointSize(5);

	for (int i = 0; i < polypoint.size(); i++)

	{

		glBegin(GL_POINTS);

		glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(polypoint[i].x, polypoint[i].y);

		glEnd();

	}


}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(50, 50);

	glutInitWindowSize(1000, 1000);//视区大小像素

	glutCreateWindow("动画");

	Init();

	glutDisplayFunc(Display);

	//glutReshapeFunc(Reshape);

	glutIdleFunc(&myIdle);

	glutMouseFunc(mymouse);

	glutMainLoop();

	return 0;

}
