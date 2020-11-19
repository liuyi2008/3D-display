#include <gl/glut.h>
#include<math.h>
#include <stdlib.h>//exit
#include <vector>

using std::vector;

struct point {

	int x, y;

}p;

vector<point>polypoint;

float y = 0.0f;//��׼����

float y2;//��׼����

float dy = 0.0006f;//�任��

float a = 1.5f;//��ֵ

int process = 1;//���ƹ��̣�1��״̬1�仯��2��2��״̬2��ص�1


void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-3.0, 15.0, -15.0, 3.0); //  ���ڣ���ֽ����������ʾ�ķ�Χ��X:-5.0~5.0, Y:-5.0~5.0  ����������һ��

	glMatrixMode(GL_MODELVIEW);

}

//void Reshape(int w, int h)
//{
//
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h); //���������ߴ�
//
//	glMatrixMode(GL_PROJECTION); //ָ����ǰ����ͶӰ�����ջ
//
//	glLoadIdentity(); //����ͶӰ����
//
//	//ָ��͸��ͶӰ�Ĺ۲�ռ�
//
//	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
//
//}

void drawTriangle_line() //����һ���µ���˫�������Σ�ԭ���������ε����ĵ㣬�����y��С�����α߳�
{
	//glEnable(GL_LINE_SMOOTH);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP); //�µ���˫

	glVertex2f(0.0f, -a);//�µ�

	glVertex2f(-a * sqrt(3) * 0.5, a * 0.5);//���

	glVertex2f(a*sqrt(3) * 0.5, a * 0.5);//�ҵ�

	glEnd();

	glBegin(GL_LINES); //����������ı仯��

	glVertex2f(-a * sqrt(3) * 0.5 + y, a * 0.5); glVertex2f(-a * sqrt(3) * 0.5 + 0.5 * y, 0.5 * a - 0.5*sqrt(3)*y);  //د

	glVertex2f(a * sqrt(3) * 0.5 - y, a * 0.5); glVertex2f(a*sqrt(3) * 0.5 - 0.5 * y, a * 0.5 - 0.5*sqrt(3)*y);  //��

	glVertex2f(0.0f - 0.5*y, -a+0.5*sqrt(3)*y); glVertex2f(0.0f+0.5*y, -a + 0.5*sqrt(3)*y);  //һ

	glEnd();

	glBegin(GL_LINES);//�������ұߣ�Χ�ɵ������εı仯��

	glVertex2f(sqrt(3)*a - y,-a); glVertex2f(sqrt(3)*a - 0.5*y, -a + 0.5*sqrt(3)*y);  //د

	glVertex2f(0.0f + y, -a); glVertex2f(0.0f+0.5*y, -a + 0.5*sqrt(3)*y);  //��

	glVertex2f(a*sqrt(3) * 0.5 - 0.5*y, a * 0.5 - 0.5*sqrt(3)*y); glVertex2f(a*sqrt(3) * 0.5 + 0.5*y, a * 0.5 - 0.5*sqrt(3)*y);  //һ

	glEnd();

}

void drawTriangle_line2() //����һ����˫�ϵ��Ļ�����Ԫ
{
	//glEnable(GL_LINE_SMOOTH);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_LOOP); //��˫�ϵ�

	glVertex2f(0.0f, 0.5 * a);//�ϵ�

	glVertex2f(-a * sqrt(3) * 0.25, -a * 0.25);//���

	glVertex2f(a*sqrt(3) * 0.25, -a * 0.25);//�ҵ�

	glEnd();

	glBegin(GL_LINES); //������

	glVertex2f(0.0f - 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2); glVertex2f(0.0f + 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2);//һ

	glVertex2f(a*sqrt(3) * 0.25 - y2, -a * 0.25); glVertex2f(a*sqrt(3) * 0.25 - 0.5*y2, -a * 0.25 + 0.5*sqrt(3)*y2); //د

	glVertex2f(-a * sqrt(3) * 0.25 + y2, -a * 0.25); glVertex2f(-a * sqrt(3) * 0.25 + 0.5* y2, -a * 0.25 + 0.5*sqrt(3)*y2); //��

	glEnd();

	glBegin(GL_LINES);  //�ұ߿������������

	glVertex2f(a*sqrt(3) * 0.25-0.5*y2, -a * 0.25+0.5*sqrt(3)*y2); glVertex2f(a*sqrt(3) * 0.25+0.5*y2, -a * 0.25 + 0.5*sqrt(3)*y2);//һ

	glVertex2f(0.0f + y2, 0.5 * a); glVertex2f(0.0f+0.5*y2, 0.5 * a-0.5*sqrt(3)*y2); //د

	glVertex2f(0.5*sqrt(3)*a - y2, 0.5 * a); glVertex2f(0.5*sqrt(3)*a - 0.5*y2, 0.5 * a - 0.5*sqrt(3)*y2); //��

	glEnd();

}

void Display(void) //������������������
{
	glClear(GL_COLOR_BUFFER_BIT);//�����ɫ����Ȼ�����

	for (int i = 0; i < 10; i++) // ��i��,j��
	{
		glLoadIdentity(); //����ģ����ͼ����

		glTranslatef(i % 2 * 0.5 * sqrt(3) * a, i*-1.5 * a, 0.0);  //��һ�� ��j%2 ��һ��������һ�в���

		drawTriangle_line();

		for (int j = 1; j < 10; j++) //һ�л�5�����У�
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
	glClear(GL_COLOR_BUFFER_BIT);//�����ɫ����Ȼ�����

	for (int i = 0; i < 15; i++) // ��i��,j��
	{
		glLoadIdentity(); //����ģ����ͼ����

		glTranslatef(i % 2 * 0.25 * sqrt(3) * a, i * -0.75 * a, 0.0);  //��һ�� ��i%2 ��һ��������һ�в���

		drawTriangle_line2();

		for (int j = 1; j < 15; j++) //һ�л�5�����У�
		{
			glTranslatef(0.5 * sqrt(3) * a, 0.0, 0.0);

			drawTriangle_line2();

		}

	}

	glFlush();

	glLoadIdentity();

}

void myIdle(void) //�ڿ���ʱ���ã��ﵽ����Ч��
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

		glClear(GL_COLOR_BUFFER_BIT);//�����ɫ����Ȼ�����

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

	glutInitWindowSize(1000, 1000);//������С����

	glutCreateWindow("����");

	Init();

	glutDisplayFunc(Display);

	//glutReshapeFunc(Reshape);

	glutIdleFunc(&myIdle);

	glutMouseFunc(mymouse);

	glutMainLoop();

	return 0;

}
