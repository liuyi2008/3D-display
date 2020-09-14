#include <gl/glut.h>  
#include<iostream>

struct point
{
	double x, y, z;
};
using namespace std;
float	rtri;
float	rquad;
GLfloat points0[5][3] = { { 0, 1,  0}, {-1, -1, 1}, { 1, -1, 1}, {	1, -1, -1},{-1, -1,-1} };
GLfloat points1[8][3] = { { 1, 1, -1 }, {-1, 1, -1}, {-1, 1, 1}, { 1, 1, 1},{ 1, -1, 1 }, {-1, -1, 1}, {-1,-1,-1}, { 1, -1, -1} };

GLfloat Colors0[4][3] = { {1,0,0},{0,1,0}, {0,0,1},{1,1,0} };	//����׶����ɫ
GLfloat Colors1[6][3] = { {0,1,0},{1,0.5,0},{1,0,0},{1,1,0},{0,0,1},{1,0,1} };//���������ɫ

int vertice0[4][3] = { {0,1,2},{0,2,3},{0,3,4},{0,4,1} };	//����׶�Ķ��������
int vertice1[6][4] = { {0,1,2,3},{4,5,6,7},{3,2,5,4},{7,6,1,0},{2,1,6,5}, {0,3,4,7} };//������Ķ��������
void InitGL(GLvoid)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void CreatePyramid()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 4; i++)
	{
		glColor3fv(Colors0[i]);
		for (int j = 0; j < 3; j++)
		{
			int VtxId = vertice0[i][j];
			glVertex3fv(points0[VtxId]);
		}
	}
	glEnd();
	glBegin(GL_QUADS); 	//��������
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 1; i < 4; i++)
		glVertex3fv(points0[i]);
	glEnd();
}
void CreateCube()
{
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		glColor3fv(Colors1[i]);
		for (int j = 0; j < 4; j++)
		{
			int VtxId = vertice1[i][j];
			glVertex3fv(points1[VtxId]);
		}
	}
	glEnd();
}
void CreateCell()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 6; i++)
	{
		glColor3fv(Colors1[i]);
		for (int j = 0; j < 4; j++)
		{
			int VtxId = vertice1[i][j];
			glVertex3fv(points1[VtxId]);
		}
	}
	glEnd();
}

void triangle(int i)  //��i�㣬��1��ʼ����i��wһ�������A��B��C��λ��
{
	float Thickness = 0.2; // һ��ĺ��

	float a = 100.0f;//��λ���� ��������������

	float width = 1.2; //��ͷ�Ŀ��,���߱仯������

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
		for (m; m < 10; m++)  //�׶�һ��w*i �� 0����sqrt(3)/3 *a
		{
			for (n; n < 10; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) };

				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                         m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                             m*0.5*sqrt(3)*a + 0 };

			}
			n = 0;
		}
		break;
	}
	case 2:
	{
		for (m; m < 10; m++)   //�׶ζ���w*i�� sqrt(3)/3 *a����2 * sqrt(3)/3 *a
		{
			for (n; n < 10; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };

				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };



			}
			n = 0;
		}
		break;
	}
	case 3:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		for (m; m < 10; m++)  //�׶������ͽ׶�һ������ֻ��Y����ȫ��ɸ�
		{
			for (n; n < 10; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };

				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 };


			}
			n = 0;
		}
		break;
	}
	case 4:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		for (m; m < 10; m++)  //�׶��ģ��ͽ׶ζ�һ��
		{
			for (n; n < 10; n++)
			{
				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };

				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };

				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };

				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };


			}
			n = 0;
		}
		break;
	}

	default: printf("������");
		break;
	}

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	//glTranslatef(-1.5f, 0.0f, -6.0f);	//ƽ�������
	//glRotatef(rtri, 1.0f, 1.0f, 0.0f);	//��תһ���Ƕ�
	//CreatePyramid();	//����������

	//glLoadIdentity();	//�������һ����ԭ��    
	//glTranslatef(1.5f, 0.0f, -6.0f);	//ƽ�Ƶ��Ҳ�
	//glRotatef(rquad, 0.0f, 1.0f, 0.0f);	//��תһ���Ƕ�
	//CreateCube(); 	//����������
	//glPopMatrix();

	//rtri += 0.2f;	//�޸���������ת�Ƕ�
	//rquad -= 0.15f;	//�޸����������ת�Ƕ�


	glTranslatef(0.0f, 0.0f, -6.0f);
	//glRotatef(rtri, 1.0f, 0.0f, 0.0f);	//��תһ���Ƕ�
	glBegin(GL_QUADS);
	glColor3f(1.0f,0.0f,0.0f);//red
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);//green
	glVertex3f(100, 0, 0);

	glColor3f(0.0f, 0.0f, 1.0f);//blue
	glVertex3f(0, 100, 0);

	glColor3f(0.0f, 0.0f, 0.0f);//black
	glVertex3f(0, 0, 100);
	glEnd();
	//rtri += 0.2f;	

	glutSwapBuffers();
}
void reshape(int width, int height)
{
	if (height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Pyramid and cube");
	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
}
