#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>
#include <vector>

using std::vector;
using namespace std;

struct point { GLfloat x, y; };
vector<point>tripoint;

//������ӽ��й�
double xs = 0;
double ys = 0;
double zs = 0;

double sx = 0;
double sy = 0;
double sz = 0;

//GLfloat rquad = 0;
//GLfloat vertices[8][3] = { {-1.0, -1.0, 1.0},{-1.0, 1.0, 1.0},{1.0,1.0, 1.0},{1.0,-1.0,1.0},{-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0} };
//GLfloat vertices[8][3] = { {-10.1, -20.8, 30.2},{-10.21, 20.75, 30.0},{10.1,20.2, 30.3},{10.4,-20.5,30.8},{-10.4,-20.1,-30.4}, {-10.2,20.3,-30.8},{10.1,20.7,-30.8}, {10.0,-20.9,-30.0} };
GLfloat vertices[8][3] = { {0.0,0.0,120.0},{0.0,120.0,120.0} ,{120.0,120.0,120.0},{120.0,0.0,120.0},{0.0,0.0,0.0},{0.0,120.0,0.0} ,{120.0,120.0,0.0},{120.0,0.0,0.0} };
GLfloat colors[7][3] = { {1.0,1.0,1.0}, {1.0,0.0,0.0}, {1.0,1.0,0.0},{0.0,0.0,1.0}, {1.0,0.0,1.0}, {0.0,1.0,1.0} ,{0.0,0.0,0.0} };

void InitGL(GLvoid)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//void Polygon(int clr, int a, int b, int c, int d)
//{
//	glColor3fv(colors[clr]);
//	if (flag == 1)
//		glBegin(GL_LINE_LOOP);
//	else
//		glBegin(GL_POLYGON);
//
//	glVertex3fv(vertices[a]);
//	glVertex3fv(vertices[b]);
//	glVertex3fv(vertices[c]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void ColorCube(void)
//{
//	//Polygon(0, 0, 3, 2, 1);
//	//Polygon(1, 2, 3, 7, 6);
//	//Polygon(2, 0, 4, 7, 3);
//	//Polygon(3, 1, 2, 6, 5);
//	//Polygon(4, 4, 5, 6, 7);
//	//Polygon(5, 0, 1, 5, 4);
//
//	Polygon(6, 0, 3, 2, 1);
//	Polygon(6, 2, 3, 7, 6);
//	Polygon(6, 0, 4, 7, 3);
//	Polygon(6, 1, 2, 6, 5);
//	Polygon(6, 4, 5, 6, 7);
//	Polygon(6, 0, 1, 5, 4);
//}

void Polygon(int clr, int a, int b, int c, int d)
{
	glColor3fv(colors[clr]);

	glPointSize(5);
	glBegin(GL_LINE_LOOP);

	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);

	glEnd();
}

void ColorCube(void)
{

	Polygon(6, 0, 3, 2, 1);
	Polygon(6, 2, 3, 7, 6);
	Polygon(6, 0, 4, 7, 3);
	Polygon(6, 1, 2, 6, 5);
	Polygon(6, 4, 5, 6, 7);
	Polygon(6, 0, 1, 5, 4);
}

point trans(point p, float b, float c)  //����ƽ��  �����ƺ���Ӧ�����ţ�ֻ��Ҫƽ��
{
	//a ���ű���,b ����ƽ��,c ����ƽ��
	p = { p.x + b , p.y + c };
	return p;
}

void triangle(int i)  //��i�㣬��1��ʼ����i��wһ�������A��B��C��λ��  1��
{
	i = i + 15;
	float a = 10.0f;// �����α߳� ��������������

	float width = 0.4; //��ͷ�Ŀ��,���߱仯�����ʣ����ڿ�������ÿ��ƫ�Ƶľ��룬����ʵ��ͷ�����Ͼ����˽Ƕȣ����仯��

	int m = 0;  //��
	int n = 0;  //��
	//************************�������i,ʹ֮ӳ��������0��4*sqrt(3)*0.333*a��*****************************
	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
	{
		i = i - int(4 * sqrt(3)*0.333*a / width);
	}
	int condition;
	if (i - 1 < sqrt(3)*0.333*a / width)
	{
		condition = 1;
	}
	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
	{
		condition = 2;
	}
	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
	{
		condition = 3;
	}
	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
	{
		condition = 4;
	}
	//************************�������i,ʹ֮ӳ��������0��4*sqrt(3)*0.333*a��*****************************
	switch (condition)
	{
	case 1:
	{
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //�׶�һ��w*i �� 0����sqrt(3)/3 *a
		{
			for (n; n < 170 / a; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) };

				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                         m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                             m*0.5*sqrt(3)*a + 0 };

				tripoint.push_back(trans(E,-50,0)); tripoint.push_back(trans(B, -50, 0));
				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(F, -50, 0));
				//tripoint.push_back(trans(F,-50,0)); tripoint.push_back(trans(C,-50,0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(D, -50, 0));
				//tripoint.push_back(trans(D,-50,0)); tripoint.push_back(trans(A,-50,0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				//tripoint.push_back(trans(B,-50,0)); tripoint.push_back(trans(E,-50,0));

			}
			n = 0;
		}
		break;
	}
	case 2:
	{
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //�׶ζ���w*i�� sqrt(3)/3 *a����2 * sqrt(3)/3 *a
		{
			for (n; n < 170 / a; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };

				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };

				tripoint.push_back(trans(E, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(F, -50, 0));
				//tripoint.push_back(trans(F,-50,0)); tripoint.push_back(trans(C,-50,0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(D, -50, 0));
				//tripoint.push_back(trans(D,-50,0)); tripoint.push_back(trans(A,-50,0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				//tripoint.push_back(trans(B,-50,0)); tripoint.push_back(trans(E,-50,0));

			}
			n = 0;
		}
		break;
	}
	case 3:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //�׶������ͽ׶�һ������ֻ��Y����ȫ��ɸ�
		{
			for (n; n < 170 / a; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };

				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 };

				tripoint.push_back(trans(E, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(F, -50, 0));
				//tripoint.push_back(trans(F,-50,0)); tripoint.push_back(trans(C,-50,0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(D, -50, 0));
				//tripoint.push_back(trans(D,-50,0)); tripoint.push_back(trans(A,-50,0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				//tripoint.push_back(trans(B,-50,0)); tripoint.push_back(trans(E,-50,0));

			}
			n = 0;
		}
		break;
	}
	case 4:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //�׶��ģ��ͽ׶ζ�һ��
		{
			for (n; n < 170 / a; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };

				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };

				tripoint.push_back(trans(E, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(F, -50, 0));
				//tripoint.push_back(trans(F,-50,0)); tripoint.push_back(trans(C,-50,0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(D, -50, 0));
				//tripoint.push_back(trans(D,-50,0)); tripoint.push_back(trans(A,-50,0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(B, -50, 0));
				//tripoint.push_back(trans(B,-50,0)); tripoint.push_back(trans(E,-50,0));

			}
			n = 0;
		}
		break;
	}

	default: printf("������");
		break;
	}

}

void lines()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	/*for (int i = 0; i < tripoint.size(); i += 2)
	{
		printf("x%f,y%f,z%f",tripoint[i].x, tripoint[i].y, tripoint[i].z);
		printf("x%f,y%f,z%f\n", tripoint[i + 1].x, tripoint[i + 1].y, tripoint[i + 1].z);
	}*/

	for (int i = 0; i < tripoint.size(); i += 2)
	{
		glVertex3f(tripoint[i].x, tripoint[i].y, 0);  glVertex3f(tripoint[i + 1].x, tripoint[i + 1].y, 0);
	}

	glEnd();
	//tripoint.clear();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);  glVertex3f(0, 0, 0); glVertex3f(100, 0, 0);
	glColor3f(0.0, 1.0, 0.0); glVertex3f(0, 0, 0); glVertex3f(0, 100, 0);
	glColor3f(0.0, 0.0, 1.0); glVertex3f(0, 0, 0); glVertex3f(0, 0, 100);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();

	gluLookAt(0 + xs, 0 + ys, 60 + zs, 0 + xs, 0 + ys, 0, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -1.0f);	//ƽ��
	//glRotatef(rquad, 1.0f, 0.0f, 0.0f);	//��תһ���Ƕ�
	ColorCube();
	lines();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5);

	glBegin(GL_POINTS);
	//glVertex3f(0,0,0);
	//glVertex3f(-50, 0, 1);
	glVertex3f(60, 60, 60);
	glEnd();
	glPopMatrix();

	//rquad -= 0.15f;	//�޸����������ת�Ƕ�
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.0f, 100.0f);
	gluPerspective(90.0f, (GLfloat)width / (GLfloat)height, 0.0f, 100.0f);
	//if (width <= height)
	//	glOrtho(-2.0, 2.0, -2.0*(GLfloat)height / (GLfloat)width, 2.0*(GLfloat)height / (GLfloat)width, 1.0, 20.0);
	//else
	//	glOrtho(-2.0*(GLfloat)width / (GLfloat)height, 2.0*(GLfloat)width / (GLfloat)height, -2.0, 2.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myMouse(int button, int state, int x, int y)
{
	//if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	//	mousetate = 1;
	//	Oldx = x;
	//	Oldy = y;
	//}
	//if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	//	mousetate = 0;
	//�����¼�
	if (state == GLUT_UP && button == 3) {

		zs -= 1;
	}
	if (state == GLUT_UP && button == 4) {

		zs += 1;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		sy += 10;
		glutPostRedisplay();
		break;
	case 's':
		sy -= 10;
		glutPostRedisplay();
		break;
	case 'a':
		sx -= 10;
		glutPostRedisplay();
		break;
	case 'd':
		sx += 10;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void SpecialKey(GLint key, GLint x, GLint y)
{
	if (key == GLUT_KEY_UP)
	{
		ys += 10;
	}
	if (key == GLUT_KEY_LEFT)
	{
		xs -= 10;
	}
	if (key == GLUT_KEY_DOWN)
	{
		ys -= 10;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		xs += 10;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	triangle(1);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hello Cube");
	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(&SpecialKey);
	glutMainLoop();

	return 0;
}
