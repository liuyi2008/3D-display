#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>
#include <vector>

using std::vector;
using namespace std;

struct point { GLfloat x, y; };
vector<point>tripoint;

//与调节视角有关
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

point trans(point p, float b, float c)  //坐标平移  这里似乎不应该缩放，只需要平移
{
	//a 缩放倍数,b 左右平移,c 上下平移
	p = { p.x + b , p.y + c };
	return p;
}

/*
void getcoord(point A, point B)
{
	float xmin, xmax, y, ymin, ymax;
	float x1, x2, y1, y2;
	x1 = A.x;
	y1 = A.y;
	x2 = B.x;
	y2 = B.y;

	float a = (y2 - y1) / (x2 - x1);
	float b = y1 - x1 * a;

	if (A.x > B.x)
	{
		xmin = x2;
		ymin = x2;
		xmax = x1;
		ymax = y1;
	}
	else
	{
		xmin = x1;
		ymin = y1;
		xmax = x2;
		ymax = y2;

	}
	//p = { xmin , ymin };
	//coord.push_back(p);
	for (; xmin < xmax;)
	{
		y = a * xmin + b;
		p = { int(xmin) , int(y) };
		coord2.push_back(p);
		xmin++;

	}
	p = { int(xmax) , int(ymax) };
	coord2.push_back(p);


}*/

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置     单层
//{
//	float a = 30.0f;// 三角形边长 这里来控制缩放
//
//	float width = 0.4; //喷头的宽度,或者变化的速率，现在看来就是每次偏移的距离，和真实碰头宽度配合决定了角度，即变化率
//
//	int m = 0;  //行
//	int n = 0;  //列
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i - 1 < sqrt(3)*0.333*a / width)
//	{
//		condition = 1;
//	}
//	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) };
//
//				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				point D = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };
//
//				point E = { m * 0.5 * a + n * a + 0 ,                         m*0.5*sqrt(3)*a + 0 };
//
//				point F = { m*0.5*a + n * a + a ,                             m*0.5*sqrt(3)*a + 0 };
//
//				tripoint.push_back(trans(E)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(F));
//				//tripoint.push_back(trans(F)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(D));
//				//tripoint.push_back(trans(D)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(B));
//				//tripoint.push_back(trans(B)); tripoint.push_back(trans(E));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };
//
//				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };
//
//				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };
//
//				tripoint.push_back(trans(E)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(F));
//				//tripoint.push_back(trans(F)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(D));
//				//tripoint.push_back(trans(D)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(B));
//				//tripoint.push_back(trans(B)); tripoint.push_back(trans(E));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };
//
//				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };
//
//				point D = { m*0.5*a + n * a + 0.5*a ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };
//
//				point E = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 };
//
//				point F = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 };
//
//				tripoint.push_back(trans(E)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(F));
//				//tripoint.push_back(trans(F)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(D));
//				//tripoint.push_back(trans(D)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(B));
//				//tripoint.push_back(trans(B)); tripoint.push_back(trans(E));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };
//
//				point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };
//
//				point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };
//
//				tripoint.push_back(trans(E)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(F));
//				//tripoint.push_back(trans(F)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(D));
//				//tripoint.push_back(trans(D)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(B));
//				//tripoint.push_back(trans(B)); tripoint.push_back(trans(E));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//
//
//}

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置
//{
//	float Thickness = 0.2; // 一层的厚度
//
//	float a = 30.0f;//单位距离 这里来控制缩放
//
//	float width = 1.2; //喷头的宽度,或者变化的速率
//
//	int m = 0;  //行
//	int n = 0;  //列
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i -1 < sqrt(3)*0.333*a / width )
//	{
//		condition = 1;
//	}
//	else if (i -1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i -1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i -1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		for (m; m < 1/*(120*2)/(sqrt(3)*a)*/; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 1/*170/a*/; n++)
//			{
//		//for (m; m < (120*2)/(sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		//{
//		//	for (n; n < 170/a; n++)
//		//	{
//				//point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) };
//
//				//point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				//point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				//point D = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a  };
//
//				//point E = { m * 0.5 * a + n * a + 0 ,                         m*0.5*sqrt(3)*a + 0  };
//
//				//point F = { m*0.5*a + n * a + a ,                             m*0.5*sqrt(3)*a + 0  };
//
//				//tripoint.push_back(trans(E)); tripoint.push_back(trans(B));
//				//tripoint.push_back(trans(B)); tripoint.push_back(trans(C));
//				//tripoint.push_back(trans(C)); tripoint.push_back(trans(F));
//				////tripoint.push_back(trans(F)); tripoint.push_back(trans(C));
//				//tripoint.push_back(trans(C)); tripoint.push_back(trans(A));
//				//tripoint.push_back(trans(A)); tripoint.push_back(trans(D));
//				////tripoint.push_back(trans(D)); tripoint.push_back(trans(A));
//				//tripoint.push_back(trans(A)); tripoint.push_back(trans(B));
//				////tripoint.push_back(trans(B)); tripoint.push_back(trans(E));
//
//				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) - width };
//
//				point A1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,               m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) - 0.167*sqrt(3)*width };
//
//				point A2 = { m*0.5*a + n * a + 0.5*a + 0.5*width,               m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) - 0.167*sqrt(3)*width };
//
//				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) + 0.5*sqrt(3)*width ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) +0.5*width };
//
//				point B1 = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) + 0.33*sqrt(3)*width };
//
//				point B2 = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) + 0.5*width,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) - sqrt(3) * 0.167 *width };
//
//				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) - 0.5*sqrt(3)*width  ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) + 0.5*width };
//
//				point C1 = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) - 0.5*width ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) - sqrt(3) * 0.167 *width };
//
//				point C2 = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) + sqrt(3) * 0.33 *width };
//
//				point D1 = { m*0.5*a + n * a + 0.5*a - 0.5*width ,              m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a - 0.167*sqrt(3)*width };
//
//				point D2 = { m*0.5*a + n * a + 0.5*a + 0.5*width ,              m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a - 0.167*sqrt(3)*width };
//
//				point E1 = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width  };
//
//				point E2 = { m * 0.5 * a + n * a + 0 + 0.5*width,                          m*0.5*sqrt(3)*a + 0 - sqrt(3) * 0.167 *width };
//
//				point F1 = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point F2 = { m*0.5*a + n * a + a - 0.5*width,                              m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		//for (m; m < 1/*(120*2)/(sqrt(3)*a)*/; m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		//{
//		//	for (n; n < 1/*170/a*/; n++)
//		//	{
//		for (m; m < (120*2)/(sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170/a; n++)
//			{
//
//				//point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				//point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				//point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				//point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };
//
//				//point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };
//
//				//point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };
//
//				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + width };
//
//				point A1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,               m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + width +width-0.167*sqrt(3)*width };
//
//				point A2 = { m*0.5*a + n * a + 0.5*a + 0.5*width,               m*0.5*sqrt(3)*a + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + width +width-0.167*sqrt(3)*width };
//
//				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) - 0.5*sqrt(3)*width ,     m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width };
//
//				point B1 = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) - 0.5*sqrt(3)*width  ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width - 0.5*width + sqrt(3) * 0.33 *width };
//
//				point B2 = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) - 0.5*sqrt(3)*width - 0.5*sqrt(3)*width + 0.5*width,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width - 0.5*width - sqrt(3) * 0.167 *width };
//
//				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) + 0.5*sqrt(3)*width ,       m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width };
//
//				point C1 = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) + 0.5*sqrt(3)*width - 0.25*width ,   m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width - sqrt(3) * 0.25 *width };
//
//				point C2 = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) + 0.5*sqrt(3)*width + 0.25*width ,   m*0.5*sqrt(3)*a + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width + sqrt(3) * 0.25 *width };
//
//				point D1 = { m*0.5*a + n * a + 0.5*a - 0.5*width ,              m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a - 0.167*sqrt(3)*width };
//
//				point D2 = { m*0.5*a + n * a + 0.5*a + 0.5*width ,              m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a - 0.167*sqrt(3)*width };
//
//				point E1 = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point E2 = { m * 0.5 * a + n * a + 0 + 0.5*width,                          m*0.5*sqrt(3)*a + 0 - sqrt(3) * 0.167 *width };
//
//				point F1 = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point F2 = { m*0.5*a + n * a + a - 0.5*width,                              m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < 1/*(120*2)/(sqrt(3)*a)*/; m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
//		{
//			for (n; n < 1/*170/a*/; n++)
//			{
//				//point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				//point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };
//
//				//point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) };
//
//				//point D = { m*0.5*a + n * a + 0.5*a ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };
//
//				//point E = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 };
//
//				//point F = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 };
//
//				point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) + width };
//
//				point A1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point A2 = { m*0.5*a + n * a + 0.5*a + 0.5*width,                         m*0.5*sqrt(3)*a - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) + 0.5*sqrt(3)*width,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) - 0.5*width };
//
//				point B1 = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) - 0.25*width,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) - sqrt(3) * 0.25 *width };
//
//				point B2 = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) + 0.25*width,       m*0.5*sqrt(3)*a - 0.5*width * (i - 1) + sqrt(3) * 0.25 *width };
//
//				point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) - 0.5*sqrt(3)*width,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) - 0.5*width };
//
//				point C1 = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) - 0.25*width,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) + sqrt(3) * 0.25 *width };
//
//				point C2 = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) + 0.25*width,   m*0.5*sqrt(3)*a - 0.5*width * (i - 1) - sqrt(3) * 0.25 *width };
//
//				point D1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a + 0.167*sqrt(3)*width };
//
//				point D2 = { m*0.5*a + n * a + 0.5*a + 0.5*width ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a + 0.167*sqrt(3)*width };
//
//				point E1 = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point E2 = { m * 0.5 * a + n * a + 0 + 0.5*width,                          m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//				point F1 = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point F2 = { m*0.5*a + n * a + a - 0.5*width,                              m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < 10; m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 10; n++)
//			{
//				//point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				//point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) ,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				//point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) ,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				//point D = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a };
//
//				//point E = { m * 0.5 * a + n * a + 0 ,                           m*0.5*sqrt(3)*a + 0 };
//
//				//point F = { m*0.5*a + n * a + a ,                               m*0.5*sqrt(3)*a + 0 };
//
//				point A = { m*0.5*a + n * a + 0.5*a ,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a + width };
//
//				point A1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point A2 = { m*0.5*a + n * a + 0.5*a + 0.5*width,                           m*0.5*sqrt(3)*a - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point B = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) + 0.5*sqrt(3)*width,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) - 0.5*width };
//
//				point B1 = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) - 0.25*width,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) - sqrt(3) * 0.25 *width };
//
//				point B2 = { m*0.5*a + n * a + a - sqrt(3)*0.5*width*(i - 1) + 0.25*width,     m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + sqrt(3) * 0.25 *width };
//
//				point C = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) - 0.5*sqrt(3)*width,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) - 0.5*width };
//
//				point C1 = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) - 0.25*width,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + sqrt(3) * 0.25 *width };
//
//				point C2 = { m*0.5*a + n * a + sqrt(3)*0.5*width*(i - 1) + 0.25*width,       m*0.5*sqrt(3)*a - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) - sqrt(3) * 0.25 *width };
//
//				point D1 = { m*0.5*a + n * a + 0.5*a - 0.5*width,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a + 0.167*sqrt(3)*width };
//
//				point D2 = { m*0.5*a + n * a + 0.5*a + 0.5*width ,                          m*0.5*sqrt(3)*a - 0.5*sqrt(3)*a + 0.167*sqrt(3)*width };
//
//				point E1 = { m * 0.5 * a + n * a + 0 ,                          m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point E2 = { m * 0.5 * a + n * a + 0 + 0.5*width,                          m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//				point F1 = { m*0.5*a + n * a + a ,                              m*0.5*sqrt(3)*a + 0 + 0.33*sqrt(3)*width };
//
//				point F2 = { m*0.5*a + n * a + a - 0.5*width,                              m*0.5*sqrt(3)*a + 0 - 0.167*sqrt(3)*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//}

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置         两层
//{
//	float a = 30.0f;// 三角形边长 这里来控制缩放
//
//	float width = 1.2; //喷头的宽度,或者变化的速率，现在看来就是每次偏移的距离，和真实碰头宽度配合决定了角度，即变化率
//
//	float x = a + 2 * sqrt(3)*0.33*width+0.5* width;  //x坐标右移单位
// 	float y = 0.5*sqrt(3)*a+width + 0.5*width;  //y坐标上移单位
//
//	int m = 0;  //行
//	int n = 0;  //列
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i - 1 < sqrt(3)*0.333*a / width)
//	{
//		condition = 1;
//	}
//	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		 // for (m; m < 1; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		 // {
//			//for (n; n < 1; n++)
//			//{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				//point A = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + sqrt(3) * 0.5 * a - width * (i - 1) };
//
//				//point B = { m*0.5*a + n * a + 0.5*sqrt(3)*width*(i - 1) ,       m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				//point C = { m*0.5*a + n * a + a - 0.5*sqrt(3)*width*(i - 1) ,   m*0.5*sqrt(3)*a + 0.5*width * (i - 1) };
//
//				//point D = { m*0.5*a + n * a + 0.5*a ,                         m*0.5*sqrt(3)*a + 0.5*sqrt(3)*a };
//
//				//point E = { m * 0.5 * a + n * a + 0 ,                         m*0.5*sqrt(3)*a + 0 };
//
//				//point F = { m*0.5*a + n * a + a ,                             m*0.5*sqrt(3)*a + 0 };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                         m * y + sqrt(3) * 0.5 * a - width * (i - 1) };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a -0.167*sqrt(3)*width ,    m*y + sqrt(3) * 0.5 * a - width * (i - 1) + 0.5*width };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a +0.167*sqrt(3)*width,      m*y + sqrt(3) * 0.5 * a - width * (i - 1) + 0.5*width };
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,       m*y + 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1)-0.33*sqrt(3)*width ,       m*y + 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1)-0.167*sqrt(3)*width ,       m*y + 0.5*width * (i - 1) - 0.5*width };
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y + 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1)+0.167*sqrt(3)*width ,   m*y + 0.5*width * (i - 1) - 0.5*width };
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1)+0.33*sqrt(3)*width ,   m*y + 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,                         m*y + 0.5*sqrt(3)*a + 0.5*width };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,                         m*y + 0.5*sqrt(3)*a + 0.5*width };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*width ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*width ,                         m*y + 0 - 0.5*width };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*width,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*width,                             m*y + 0 - 0.5*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//				
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*width };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*width };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*width ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*width ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*width ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*width };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*width,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,                         m*y + 0.5*sqrt(3)*a + 0.5*width };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,                         m*y + 0.5*sqrt(3)*a + 0.5*width };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*width ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*width ,                         m*y + 0 - 0.5*width };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*width,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*width,                             m*y + 0 - 0.5*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A = { m*0.5*x + n * x + 0.5*a ,                         m * y - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width ,    m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*width };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,      m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*width };
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,       m*y - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.33*sqrt(3)*width ,       m*y - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.167*sqrt(3)*width ,       m*y - 0.5*width * (i - 1) + 0.5*width };
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.167*sqrt(3)*width ,   m*y - 0.5*width * (i - 1) + 0.5*width };
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.33*sqrt(3)*width ,   m*y - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,                         m*y - 0.5*sqrt(3)*a - 0.5*width };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,                         m*y - 0.5*sqrt(3)*a - 0.5*width };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*width ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*width ,                         m*y + 0 + 0.5*width };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*width,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*width,                             m*y + 0 + 0.5*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 170 / a; n++)
//			{
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*width };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*width };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*width ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*width ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*width };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*width ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*width };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*width,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*width,                         m*y - 0.5*sqrt(3)*a - 0.5*width };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*width,                         m*y - 0.5*sqrt(3)*a - 0.5*width };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*width ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*width ,                         m*y + 0 + 0.5*width };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*width,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*width,                             m*y + 0 + 0.5*width };
//
//				tripoint.push_back(trans(B1)); tripoint.push_back(trans(A1));
//				tripoint.push_back(trans(A1)); tripoint.push_back(trans(D1));
//				tripoint.push_back(trans(D1)); tripoint.push_back(trans(D2));
//				tripoint.push_back(trans(D2)); tripoint.push_back(trans(A2));
//				tripoint.push_back(trans(A2)); tripoint.push_back(trans(C2));
//				tripoint.push_back(trans(C2)); tripoint.push_back(trans(F1));
//				tripoint.push_back(trans(F1)); tripoint.push_back(trans(F2));
//				tripoint.push_back(trans(F2)); tripoint.push_back(trans(C1));
//				tripoint.push_back(trans(C1)); tripoint.push_back(trans(B2));
//				tripoint.push_back(trans(B2)); tripoint.push_back(trans(E2));
//				tripoint.push_back(trans(E2)); tripoint.push_back(trans(E1));
//				tripoint.push_back(trans(E1)); tripoint.push_back(trans(B1));
//				//tripoint.push_back(trans(B1)); tripoint.push_back(trans(B));
//
//				tripoint.push_back(trans(B)); tripoint.push_back(trans(A));
//				tripoint.push_back(trans(A)); tripoint.push_back(trans(C));
//				tripoint.push_back(trans(C)); tripoint.push_back(trans(B));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//
//
//}

void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置         两层层第二版（由三层三版而来）
{
	float a = 30.0f;// 三角形边长 这里来控制缩放 当三角形厚度增加，不可不考虑壁厚，这里是内三角形边长

	float width = 1.2; //上层和下层的偏移的距离，和真实喷头宽度配合决定了角度，即变化率，范围(0,一个喷宽)

	float offset = 1.6;  //同层相邻路径之间的距离，理论上等于一个喷头宽度。以下代码中两线之间距离等于offset

	float x = a + 2 * sqrt(3)*offset;  //x坐标右移复制 
	float y = 0.5*sqrt(3)*a + 2 * offset + offset; //y坐标上移复制

	float x0;      //网格调整平移
	float y0;

	int m = 0;  //行 复制个数
	int n = 0;  //列 复制个数
	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
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
	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
	switch (condition)
	{
	case 1:
	{
		//for (m; m < 1; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
		//{
		//  for (n; n < 1; n++)
		//  {
		for (m; m < (120 * 2) / (sqrt(3)*x); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
		{
			for (n; n < 170 / x; n++)
			{


				point A = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) };

				//point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a + 2 * offset };//A

				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3

				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3

				//point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset }; //A

				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - offset }; //由A3推导出

				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - offset }; //由A3推导出

				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出

				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出


				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,     m*y + 0.5*width * (i - 1) };

				//point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset };

				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset };//e3

				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y + 0 - offset - 0.333*sqrt(3)*offset };//e3

				//point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset };

				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset + 2 * offset };//由B3

				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,                               m*y + 0.5*width * (i - 1) - 2 * offset }; //由B

				point B4 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset + offset ,     m*y + 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由B3

				point B5 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由B3




				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,    m*y + 0.5*width * (i - 1) };

				//point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset };

				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset }; //由f3

				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y + 0 - offset - 0.333*sqrt(3)*offset };//由f3

				//point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset,             m*y + 0.5*width * (i - 1) - offset };

				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,                             m*y + 0.5*width * (i - 1) - offset - offset }; //由c

				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset ,            m*y + 0.5*width * (i - 1) - offset + 2 * offset };//由c3

				point C4 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset  ,           m*y + 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由c3

				point C5 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset - offset,    m*y + 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由c3



				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B5, -50, 0));
				tripoint.push_back(trans(B5, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(A5, -50, 0));
				tripoint.push_back(trans(A5, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A4, -50, 0));
				tripoint.push_back(trans(A4, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(C4, -50, 0));
				tripoint.push_back(trans(C4, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C5, -50, 0));
				tripoint.push_back(trans(C5, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(B4, -50, 0));
				tripoint.push_back(trans(B4, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E1, -50, 0));

				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));

			}
			n = 0;
		}
		break;
	}
	case 2:
	{
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
		{
			for (n; n < 170 / a; n++)
			{

				point A = { m*0.5*x + n * x + 0.5*a ,               m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };

				//point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a + 2 * offset };//A

				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3

				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3

				//point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset }; //A

				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - offset }; //由A3推导出

				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - offset }; //由A3推导出

				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出

				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出


				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) , m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				//point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset };

				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset };//e3

				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y + 0 - offset - 0.333*sqrt(3)*offset };//e3

				//point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset };

				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 2 * offset };//由B3

				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,                               m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 2 * offset }; //由B

				point B4 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset + offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由B3

				point B5 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由B3



				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,        m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };

				//point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset };

				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset }; //由f3

				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y + 0 - offset - 0.333*sqrt(3)*offset };//由f3

				//point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset,             m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset };

				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,                             m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - offset }; //由c

				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset ,            m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 2 * offset };//由c3

				point C4 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset  ,           m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由c3

				point C5 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset - offset,    m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由c3




				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B5, -50, 0));
				tripoint.push_back(trans(B5, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(A5, -50, 0));
				tripoint.push_back(trans(A5, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A4, -50, 0));
				tripoint.push_back(trans(A4, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(C4, -50, 0));
				tripoint.push_back(trans(C4, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C5, -50, 0));
				tripoint.push_back(trans(C5, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(B4, -50, 0));
				tripoint.push_back(trans(B4, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E1, -50, 0));

				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));


			}
			n = 0;
		}
		break;
	}
	case 3:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		x0 = -50;
		y0 = -2 * offset + y;
		for (m; m < (120 * 2) / (sqrt(3)*x); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
		{
			for (n; n < 170 / x; n++)
			{

				point A = { m*0.5*x + n * x + 0.5*a ,               m*y - 0.5*sqrt(3)*a + width * (i - 1) };

				//point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a - 2 * offset };//A

				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3

				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3

				//point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset }; //A

				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + offset }; //由A3推导出

				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + offset }; //由A3推导出

				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出

				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出


				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,     m*y - 0.5*width * (i - 1) };

				//point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset };

				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset };//e3

				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y - 0 + offset + 0.333*sqrt(3)*offset };//e3

				//point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset };

				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset - 2 * offset };//由B3

				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,                               m*y - 0.5*width * (i - 1) + 2 * offset }; //由B

				point B4 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset + offset ,     m*y - 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由B3

				point B5 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由B3


				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,    m*y - 0.5*width * (i - 1) };

				//point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset };

				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset }; //由f3

				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y - 0 + offset + 0.333*sqrt(3)*offset };//由f3

				//point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset,             m*y - 0.5*width * (i - 1) + offset };

				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,                             m*y - 0.5*width * (i - 1) + offset + offset }; //由c

				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset ,            m*y - 0.5*width * (i - 1) + offset - 2 * offset };//由c3

				point C4 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset  ,           m*y - 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由c3

				point C5 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset - offset,    m*y - 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由c3




				tripoint.push_back(trans(E1, x0, y0)); tripoint.push_back(trans(B5, x0, y0));
				tripoint.push_back(trans(B5, x0, y0)); tripoint.push_back(trans(B1, x0, y0));
				tripoint.push_back(trans(B1, x0, y0)); tripoint.push_back(trans(A1, x0, y0));
				tripoint.push_back(trans(A1, x0, y0)); tripoint.push_back(trans(A5, x0, y0));
				tripoint.push_back(trans(A5, x0, y0)); tripoint.push_back(trans(D1, x0, y0));
				tripoint.push_back(trans(D1, x0, y0)); tripoint.push_back(trans(D2, x0, y0));
				tripoint.push_back(trans(D2, x0, y0)); tripoint.push_back(trans(A4, x0, y0));
				tripoint.push_back(trans(A4, x0, y0)); tripoint.push_back(trans(A2, x0, y0));
				tripoint.push_back(trans(A2, x0, y0)); tripoint.push_back(trans(C2, x0, y0));
				tripoint.push_back(trans(C2, x0, y0)); tripoint.push_back(trans(C4, x0, y0));
				tripoint.push_back(trans(C4, x0, y0)); tripoint.push_back(trans(F1, x0, y0));
				tripoint.push_back(trans(F1, x0, y0)); tripoint.push_back(trans(F2, x0, y0));
				tripoint.push_back(trans(F2, x0, y0)); tripoint.push_back(trans(C5, x0, y0));
				tripoint.push_back(trans(C5, x0, y0)); tripoint.push_back(trans(C1, x0, y0));
				tripoint.push_back(trans(C1, x0, y0)); tripoint.push_back(trans(B2, x0, y0));
				tripoint.push_back(trans(B2, x0, y0)); tripoint.push_back(trans(B4, x0, y0));
				tripoint.push_back(trans(B4, x0, y0)); tripoint.push_back(trans(E2, x0, y0));
				tripoint.push_back(trans(E2, x0, y0)); tripoint.push_back(trans(E1, x0, y0));

				tripoint.push_back(trans(B, x0, y0)); tripoint.push_back(trans(A, x0, y0));
				tripoint.push_back(trans(A, x0, y0)); tripoint.push_back(trans(C, x0, y0));
				tripoint.push_back(trans(C, x0, y0)); tripoint.push_back(trans(B, x0, y0));


			}
			n = 0;
		}
		break;
	}
	case 4:
	{
		i = i - 2 * sqrt(3)*0.333*a / width;
		x0 = -50;
		y0 = -2 * offset + y;
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
		{
			for (n; n < 170 / a; n++)
			{

				point A = { m*0.5*x + n * x + 0.5*a ,               m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };

				//point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a - 2 * offset };//A

				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3

				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3

				//point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset }; //A

				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + offset }; //由A3推导出

				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + offset }; //由A3推导出

				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出

				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出


				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) , m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

			//	point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset };

				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset };//e3

				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y - 0 + offset + 0.333*sqrt(3)*offset };//e3

			//	point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset };

				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 2 * offset };//由B3

				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,                               m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 2 * offset }; //由B

				point B4 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset + offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由B3

				point B5 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由B3



				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,        m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };

				//point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset };

				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset }; //由f3

				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y - 0 + offset + 0.333*sqrt(3)*offset };//由f3

				//point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset,             m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset };

				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,                             m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + offset }; //由c

				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset ,            m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 2 * offset };//由c3

				point C4 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset  ,           m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由c3

				point C5 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset - offset,    m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由c3


				tripoint.push_back(trans(E1, x0, y0)); tripoint.push_back(trans(B5, x0, y0));
				tripoint.push_back(trans(B5, x0, y0)); tripoint.push_back(trans(B1, x0, y0));
				tripoint.push_back(trans(B1, x0, y0)); tripoint.push_back(trans(A1, x0, y0));
				tripoint.push_back(trans(A1, x0, y0)); tripoint.push_back(trans(A5, x0, y0));
				tripoint.push_back(trans(A5, x0, y0)); tripoint.push_back(trans(D1, x0, y0));
				tripoint.push_back(trans(D1, x0, y0)); tripoint.push_back(trans(D2, x0, y0));
				tripoint.push_back(trans(D2, x0, y0)); tripoint.push_back(trans(A4, x0, y0));
				tripoint.push_back(trans(A4, x0, y0)); tripoint.push_back(trans(A2, x0, y0));
				tripoint.push_back(trans(A2, x0, y0)); tripoint.push_back(trans(C2, x0, y0));
				tripoint.push_back(trans(C2, x0, y0)); tripoint.push_back(trans(C4, x0, y0));
				tripoint.push_back(trans(C4, x0, y0)); tripoint.push_back(trans(F1, x0, y0));
				tripoint.push_back(trans(F1, x0, y0)); tripoint.push_back(trans(F2, x0, y0));
				tripoint.push_back(trans(F2, x0, y0)); tripoint.push_back(trans(C5, x0, y0));
				tripoint.push_back(trans(C5, x0, y0)); tripoint.push_back(trans(C1, x0, y0));
				tripoint.push_back(trans(C1, x0, y0)); tripoint.push_back(trans(B2, x0, y0));
				tripoint.push_back(trans(B2, x0, y0)); tripoint.push_back(trans(B4, x0, y0));
				tripoint.push_back(trans(B4, x0, y0)); tripoint.push_back(trans(E2, x0, y0));
				tripoint.push_back(trans(E2, x0, y0)); tripoint.push_back(trans(E1, x0, y0));

				tripoint.push_back(trans(B, x0, y0)); tripoint.push_back(trans(A, x0, y0));
				tripoint.push_back(trans(A, x0, y0)); tripoint.push_back(trans(C, x0, y0));
				tripoint.push_back(trans(C, x0, y0)); tripoint.push_back(trans(B, x0, y0));

			}
			n = 0;
		}
		break;
	}

	default: printf("有问题");
		break;
	}

}

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置         三层
//{
//	float a = 30.0f;// 三角形边长 这里来控制缩放 当三角形厚度增加，不可不考虑壁厚，这里是内三角形边长
//
//	float width = 1.2; //上层和下层的偏移的距离，和真实喷头宽度配合决定了角度，即变化率，范围(0,一个喷宽)
//	//这个变量控制线与线之间的距离，在下面的句意中所有路径间距0.5*width，在实际打印中喷头宽度要大于0.5*width,打双层时要等于0.5*width，打3层时等于0.25*width
//
//	float offset = 1.6;  //同层不同路径之间的距离，等于一个喷头宽度
//
//	float x = a + 2 * sqrt(3)*0.33*offset+0.25*offset;  //x坐标右移单位 这里是外三角形边长
//	float y = 0.5*sqrt(3)*a + offset+0.25*offset;  //y坐标上移单位
//
//	int m = 0;  //行
//	int n = 0;  //列
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i - 1 < sqrt(3)*0.333*a / width)
//	{
//		condition = 1;
//	}
//	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		// for (m; m < 1; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		// {
//		   //for (n; n < 1; n++)
//		   //{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                         m*y + sqrt(3) * 0.5 * a - width * (i - 1)+0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1)-0.25*sqrt(3)*offset ,       m*y + 0.5*width * (i - 1)-0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) +0.25*sqrt(3)*offset,   m*y + 0.5*width * (i - 1)-0.25*offset };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,                         m*y + 0.5*sqrt(3)*a +0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 -0.25*sqrt(3)*offset,                         m*y + 0 -0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a +0.25*sqrt(3)*offset,                             m*y + 0 -0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                         m * y + sqrt(3) * 0.5 * a - width * (i - 1) };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset ,    m*y + sqrt(3) * 0.5 * a - width * (i - 1) + 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,      m*y + sqrt(3) * 0.5 * a - width * (i - 1) + 0.5*offset };
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,       m*y + 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.33*sqrt(3)*offset ,       m*y + 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.167*sqrt(3)*offset ,       m*y + 0.5*width * (i - 1) - 0.5*offset };
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y + 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.167*sqrt(3)*offset ,   m*y + 0.5*width * (i - 1) - 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.33*sqrt(3)*offset ,   m*y + 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 - 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 - 0.5*offset };
//
//			
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                           m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.25*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.25*sqrt(3)*offset ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.25*offset };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,                           m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                           m*y + 0 - 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset,                               m*y + 0 - 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*offset };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*offset ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*offset,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 - 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 - 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		a = a + 0.33*sqrt(3)*offset;
//		x = a + 2 * sqrt(3)*0.33*offset + 0.25*offset;  //x坐标右移单位 这里是外三角形边长
//	    y = 0.5*sqrt(3)*a + offset + 0.25*offset;  //y坐标上移单位
//
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                         m*y - sqrt(3) * 0.5 * a + width * (i - 1) -0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) -0.25*sqrt(3)*offset,       m*y - 0.5*width * (i - 1) +0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.25*sqrt(3)*offset,   m*y - 0.5*width * (i - 1) + 0.25*offset };
//
//				point D3 = { m*0.5*x + n *x + 0.5*a ,                          m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                          m*y + 0 + 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset ,                              m*y + 0 + 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                         m * y - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset ,    m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,      m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*offset };
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,       m*y - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.33*sqrt(3)*offset ,       m*y - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.167*sqrt(3)*offset ,       m*y - 0.5*width * (i - 1) + 0.5*offset };
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.167*sqrt(3)*offset ,   m*y - 0.5*width * (i - 1) + 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.33*sqrt(3)*offset ,   m*y - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 + 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 + 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		a = a + 0.33*sqrt(3)*offset;
//		x = a + 2 * sqrt(3)*0.33*offset + 0.25*offset;  //x坐标右移单位 这里是外三角形边长
//		y = 0.5*sqrt(3)*a + offset + 0.25*offset;  //y坐标上移单位
//
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 170 / a; n++)
//			{
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                           m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a-0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1)-0.25*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1)+0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.25*sqrt(3)*offset ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.25*offset };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,                           m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                           m*y + 0 + 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset,                               m*y + 0 + 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*offset };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*offset };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*offset ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*offset,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 + 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 + 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//}

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置         三层第二版
//{
//	float a = 30.0f;// 三角形边长 这里来控制缩放 当三角形厚度增加，不可不考虑壁厚，这里是内三角形边长
//
//	float width = 1.2; //上层和下层的偏移的距离，和真实喷头宽度配合决定了角度，即变化率，范围(0,一个喷宽)
//
//	float offset = 1.6;  //同层相邻路径之间的距离，理论上等于一个喷头宽度。以下代码中两线之间距离等于offset
//
//	float x = a + 2*(sqrt(3)*offset+0.232*offset+0.5*offset);  //x坐标右移单位 这里必须是主三角形边长，如果是外三角形边长，则虚、实三角形不共边
//	float y = 0.5*sqrt(3)*a + (2+0.268+0.33*sqrt(3)+1+0.134+0.5*0.33*sqrt(3)) * offset; //y坐标上移单位
//
//	int m = 0;  //行
//	int n = 0;  //列
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i - 1 < sqrt(3)*0.333*a / width)
//	{
//		condition = 1;
//	}
//	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		 //for (m; m < 1; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		 //{
//		 //  for (n; n < 1; n++)
//		 //  {
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				
//
//				point A =  { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a + 2*offset + 0.268*offset + 0.33*sqrt(3)*offset };//A
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y + 0.5*sqrt(3)*a + 2*offset + 0.268*offset + sqrt(3)*offset - sqrt(3)*offset };//D3
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a + 2*offset + 0.268*offset + sqrt(3)*offset - sqrt(3)*offset };//D3
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2*offset }; //A
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - offset ,     m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2*offset + 0.268*offset }; //由A3推导出
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2*offset + 0.268*offset }; //由A3推导出
//
//
//				point B =  { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,                                     m*y + 0.5*width * (i - 1) };
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,                    m*y + 0.5*width * (i - 1) - offset };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset + 0.268*offset ,     m*y + 0.5*width * (i - 1) - offset- offset };//由B3
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset - 0.728*offset,     m*y + 0.5*width * (i - 1) - offset + 0.728*offset}; //由B3
//
//				point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset - 0.232*offset - 0.5*offset,     m*y + 0 - offset - 0.134*offset - 0.5*0.33*sqrt(3)*offset};
//
//				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset - 0.232*offset - 0.5*offset,     m*y + 0 - offset - 0.134*offset + 0.5*sqrt(3)*offset };//b3
//
//				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset - 0.232*offset + 0.5*offset,     m*y + 0 - offset - 0.134*offset - 0.5*sqrt(3)*offset };//b3
//
//
//				point C =  { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y + 0.5*width * (i - 1) };
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset,                   m*y + 0.5*width * (i - 1) - offset };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset - 0.268*offset ,   m*y + 0.5*width * (i - 1) - offset - offset }; //由c
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset + 0.728*offset,    m*y + 0.5*width * (i - 1) - offset + 0.728*offset};//由c3
//
//				point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset + 0.232*offset + 0.5*offset,    m*y + 0 - offset - 0.134*offset - 0.5*0.33*sqrt(3)*offset };
//
//				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset + 0.232*offset + 0.5*offset,    m*y + 0 - offset - 0.134*offset + 0.5*sqrt(3)*offset }; //由f3
//
//				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset + 0.232*offset - 0.5*offset,    m*y + 0 - offset - 0.134*offset - 0.5*sqrt(3)*offset };//由f3
//
//			
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(D3, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(F3, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                           m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.25*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.25*sqrt(3)*offset ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.25*offset };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,                           m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                           m*y + 0 - 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset,                               m*y + 0 - 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 0.5*offset };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*offset };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*offset ,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*offset,       m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y + 0.5*sqrt(3)*a + 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 - 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 - 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		a = a + 0.33*sqrt(3)*offset;
//		x = a + 2 * sqrt(3)*0.33*offset + 0.25*offset;  //x坐标右移单位 这里是外三角形边长
//	    y = 0.5*sqrt(3)*a + offset + 0.25*offset;  //y坐标上移单位
//
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
//		{
//			for (n; n < 170 / a; n++)
//			{
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                         m*y - sqrt(3) * 0.5 * a + width * (i - 1) -0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) -0.25*sqrt(3)*offset,       m*y - 0.5*width * (i - 1) +0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.25*sqrt(3)*offset,   m*y - 0.5*width * (i - 1) + 0.25*offset };
//
//				point D3 = { m*0.5*x + n *x + 0.5*a ,                          m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                          m*y + 0 + 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset ,                              m*y + 0 + 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                         m * y - sqrt(3) * 0.5 * a + width * (i - 1) };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset ,    m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,      m*y - sqrt(3) * 0.5 * a + width * (i - 1) - 0.5*offset };
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,       m*y - 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.33*sqrt(3)*offset ,       m*y - 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - 0.167*sqrt(3)*offset ,       m*y - 0.5*width * (i - 1) + 0.5*offset };
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,   m*y - 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.167*sqrt(3)*offset ,   m*y - 0.5*width * (i - 1) + 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + 0.33*sqrt(3)*offset ,   m*y - 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 + 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 + 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				//tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				//tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		a = a + 0.33*sqrt(3)*offset;
//		x = a + 2 * sqrt(3)*0.33*offset + 0.25*offset;  //x坐标右移单位 这里是外三角形边长
//		y = 0.5*sqrt(3)*a + offset + 0.25*offset;  //y坐标上移单位
//
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 170 / a; n++)
//			{
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,                           m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a-0.5*offset };
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1)-0.25*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1)+0.25*offset };
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.25*sqrt(3)*offset ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.25*offset };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,                           m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E3 = { m * 0.5 * x + n * x + 0 - 0.25*sqrt(3)*offset,                           m*y + 0 + 0.25*offset };
//
//				point F3 = { m*0.5*x + n * x + a + 0.25*sqrt(3)*offset,                               m*y + 0 + 0.25*offset };
//
//				point A = { m*0.5*x + n * x + 0.5*a ,                           m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*offset };
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 0.5*offset };
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.33*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - 0.167*sqrt(3)*offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*offset };
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.167*sqrt(3)*offset ,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 0.5*offset };
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + 0.33*sqrt(3)*offset,       m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + 0.167*sqrt(3)*offset,                         m*y - 0.5*sqrt(3)*a - 0.5*offset };
//
//				point E1 = { m * 0.5 * x + n * x + 0 - 0.33*sqrt(3)*offset ,                         m*y + 0 };
//
//				point E2 = { m * 0.5 * x + n * x + 0 - 0.167*sqrt(3)*offset ,                         m*y + 0 + 0.5*offset };
//
//				point F1 = { m*0.5*x + n * x + a + 0.33*sqrt(3)*offset,                             m*y + 0 };
//
//				point F2 = { m*0.5*x + n * x + a + 0.167*sqrt(3)*offset,                             m*y + 0 + 0.5*offset };
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(D2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(F2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C1, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(E2, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(E3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(D3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(F3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C3, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B3, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//				tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(A, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//				tripoint.push_back(trans(C, -50 - 0.167*sqrt(3)*offset, -0.5*offset)); tripoint.push_back(trans(B, -50 - 0.167*sqrt(3)*offset, -0.5*offset));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//}

//void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置         三层第三版
//{
//	float a = 30.0f;// 三角形边长 这里来控制缩放 当三角形厚度增加，不可不考虑壁厚，这里是内三角形边长
//
//	float width = 1.2; //上层和下层的偏移的距离，和真实喷头宽度配合决定了角度，即变化率，范围(0,一个喷宽)
//
//	float offset = 1.6;  //同层相邻路径之间的距离，理论上等于一个喷头宽度。以下代码中两线之间距离等于offset
//
//	float x = a + 2 *sqrt(3)*offset ;  //x坐标右移复制 
//	float y = 0.5*sqrt(3)*a + 2 * offset + offset; //y坐标上移复制
//
//	float x0;      //网格调整平移
//	float y0;
//
//	int m = 0;  //行 复制个数
//	int n = 0;  //列 复制个数
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	while (i - 1 > 4 * sqrt(3)*0.333*a / width)
//	{
//		i = i - int(4 * sqrt(3)*0.333*a / width);
//	}
//	int condition;
//	if (i - 1 < sqrt(3)*0.333*a / width)
//	{
//		condition = 1;
//	}
//	else if (i - 1 < 2 * sqrt(3)*0.333*a / width)
//	{
//		condition = 2;
//	}
//	else if (i - 1 < 3 * sqrt(3)*0.333*a / width)
//	{
//		condition = 3;
//	}
//	else if (i - 1 < 4 * sqrt(3)*0.333*a / width)
//	{
//		condition = 4;
//	}
//	//************************处理层数i,使之映射在区间0到4*sqrt(3)*0.333*a里*****************************
//	switch (condition)
//	{
//	case 1:
//	{
//		//for (m; m < 1; m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		//{
//		//  for (n; n < 1; n++)
//		//  {
//		for (m; m < (120 * 2) / (sqrt(3)*x); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / x; n++)
//			{
//
//
//				point A = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a + 2 * offset };//A
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y + 0.5*sqrt(3)*a + 2 * offset  - 0.333*sqrt(3)*offset };//D3
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a + 2 * offset  - 0.333*sqrt(3)*offset };//D3
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset }; //A
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - offset }; //由A3推导出
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - offset }; //由A3推导出
//
//				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset -0.333*sqrt(3)*offset }; //由A3推导出
//
//				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y + 0.5*sqrt(3)*a - width * (i - 1) + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出
//
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,     m*y + 0.5*width * (i - 1) };
//
//				point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset  };
//
//				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset + 0.333*2*sqrt(3)*offset };//e3
//
//				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y + 0 - offset - 0.333*sqrt(3)*offset };//e3
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset + 2*offset };//由B3
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,                               m*y + 0.5*width * (i - 1) - 2*offset }; //由B
//
//				point B4 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset + offset ,     m*y + 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset  };//由B3
//
//				point B5 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y + 0.5*width * (i - 1) - offset + 0.333*2*sqrt(3)*offset }; //由B3
//
//
//
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,    m*y + 0.5*width * (i - 1) };
//
//				point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset };
//
//				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset }; //由f3
//
//				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y + 0 - offset - 0.333*sqrt(3)*offset };//由f3
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset,             m*y + 0.5*width * (i - 1) - offset };
//				 
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,                             m*y + 0.5*width * (i - 1) - offset - offset }; //由c
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset ,            m*y + 0.5*width * (i - 1) - offset + 2*offset };//由c3
//
//				point C4 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset  ,           m*y + 0.5*width * (i - 1) - offset + 0.333*2*sqrt(3)*offset }; //由c3
//
//				point C5 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset - offset,    m*y + 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由c3
//
//				
//
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B5, -50, 0));
//				tripoint.push_back(trans(B5, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(A5, -50, 0));
//				tripoint.push_back(trans(A5, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(D3, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A4, -50, 0));
//				tripoint.push_back(trans(A4, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(C4, -50, 0));
//				tripoint.push_back(trans(C4, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(F3, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C5, -50, 0));
//				tripoint.push_back(trans(C5, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(B4, -50, 0));
//				tripoint.push_back(trans(B4, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 2:
//	{
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
//		{
//			for (n; n < 170 / a; n++)
//			{
//
//				point A = { m*0.5*x + n * x + 0.5*a ,               m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y + 0.5*sqrt(3)*a + 2 * offset };//A
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y + 0.5*sqrt(3)*a + 2 * offset - 0.333*sqrt(3)*offset };//D3
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset }; //A
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - offset }; //由A3推导出
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - offset }; //由A3推导出
//
//				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出
//
//				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y + width * (i - 1) - sqrt(3)*0.333*a + sqrt(3)*0.167*a + 2 * offset - 0.333*sqrt(3)*offset }; //由A3推导出
//
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) , m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset };
//
//				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset };//e3
//
//				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y + 0 - offset - 0.333*sqrt(3)*offset };//e3
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 2 * offset };//由B3
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,                               m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - 2 * offset }; //由B
//
//				point B4 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset + offset ,     m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由B3
//
//				point B5 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由B3
//
//
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,        m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) };
//
//				point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset };
//
//				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y + 0 - offset + 0.333 * 2 * sqrt(3)*offset }; //由f3
//
//				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y + 0 - offset - 0.333*sqrt(3)*offset };//由f3
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset,             m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,                             m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - offset }; //由c
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset ,            m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 2 * offset };//由c3
//
//				point C4 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset  ,           m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset + 0.333 * 2 * sqrt(3)*offset }; //由c3
//
//				point C5 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset - offset,    m*y + sqrt(3) * 0.333 * a - 0.5*width * (i - 1) - offset - 0.333*sqrt(3)*offset };//由c3
//
//
//
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(E1, -50, 0));
//				tripoint.push_back(trans(E1, -50, 0)); tripoint.push_back(trans(B5, -50, 0));
//				tripoint.push_back(trans(B5, -50, 0)); tripoint.push_back(trans(B1, -50, 0));
//				tripoint.push_back(trans(B1, -50, 0)); tripoint.push_back(trans(A1, -50, 0));
//				tripoint.push_back(trans(A1, -50, 0)); tripoint.push_back(trans(A5, -50, 0));
//				tripoint.push_back(trans(A5, -50, 0)); tripoint.push_back(trans(D1, -50, 0));
//				tripoint.push_back(trans(D1, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(D3, -50, 0)); tripoint.push_back(trans(D2, -50, 0));
//				tripoint.push_back(trans(D2, -50, 0)); tripoint.push_back(trans(A4, -50, 0));
//				tripoint.push_back(trans(A4, -50, 0)); tripoint.push_back(trans(A2, -50, 0));
//				tripoint.push_back(trans(A2, -50, 0)); tripoint.push_back(trans(C2, -50, 0));
//				tripoint.push_back(trans(C2, -50, 0)); tripoint.push_back(trans(C4, -50, 0));
//				tripoint.push_back(trans(C4, -50, 0)); tripoint.push_back(trans(F1, -50, 0));
//				tripoint.push_back(trans(F1, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(F3, -50, 0)); tripoint.push_back(trans(F2, -50, 0));
//				tripoint.push_back(trans(F2, -50, 0)); tripoint.push_back(trans(C5, -50, 0));
//				tripoint.push_back(trans(C5, -50, 0)); tripoint.push_back(trans(C1, -50, 0));
//				tripoint.push_back(trans(C1, -50, 0)); tripoint.push_back(trans(B2, -50, 0));
//				tripoint.push_back(trans(B2, -50, 0)); tripoint.push_back(trans(B4, -50, 0));
//				tripoint.push_back(trans(B4, -50, 0)); tripoint.push_back(trans(E2, -50, 0));
//				tripoint.push_back(trans(E2, -50, 0)); tripoint.push_back(trans(E3, -50, 0));
//
//				tripoint.push_back(trans(E3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//				tripoint.push_back(trans(B3, -50, 0)); tripoint.push_back(trans(A3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(D3, -50, 0));
//				tripoint.push_back(trans(A3, -50, 0)); tripoint.push_back(trans(C3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(F3, -50, 0));
//				tripoint.push_back(trans(C3, -50, 0)); tripoint.push_back(trans(B3, -50, 0));
//
//				tripoint.push_back(trans(B, -50, 0)); tripoint.push_back(trans(A, -50, 0));
//				tripoint.push_back(trans(A, -50, 0)); tripoint.push_back(trans(C, -50, 0));
//				tripoint.push_back(trans(C, -50, 0)); tripoint.push_back(trans(B, -50, 0));
//
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 3:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		x0 = -50;
//		y0 = -2*offset+y;
//		for (m; m < (120 * 2) / (sqrt(3)*x); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
//		{
//			for (n; n < 170 / x; n++)
//			{
//
//				point A = { m*0.5*x + n * x + 0.5*a ,               m*y - 0.5*sqrt(3)*a + width * (i - 1) };
//
//				point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a - 2 * offset };//A
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset }; //A
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + offset }; //由A3推导出
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + offset }; //由A3推导出
//
//				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出
//
//				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y - 0.5*sqrt(3)*a + width * (i - 1) - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出
//
//
//				point B = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,     m*y - 0.5*width * (i - 1) };
//
//				point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset };
//
//				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset };//e3
//
//				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y - 0 + offset + 0.333*sqrt(3)*offset };//e3
//
//				point B3 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset };
//
//				point B1 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset - 2 * offset };//由B3
//
//				point B2 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) ,                               m*y - 0.5*width * (i - 1) + 2 * offset }; //由B
//
//				point B4 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset + offset ,     m*y - 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由B3
//
//				point B5 = { m*0.5*x + n * x + 0.5*sqrt(3)*width*(i - 1) - sqrt(3)*offset ,              m*y - 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由B3
//
//
//				point C = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,    m*y - 0.5*width * (i - 1) };
//
//				point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset };
//
//				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset }; //由f3
//
//				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y - 0 + offset + 0.333*sqrt(3)*offset };//由f3
//
//				point C3 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset,             m*y - 0.5*width * (i - 1) + offset };
//
//				point C1 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) ,                             m*y - 0.5*width * (i - 1) + offset + offset }; //由c
//
//				point C2 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset ,            m*y - 0.5*width * (i - 1) + offset - 2 * offset };//由c3
//
//				point C4 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset  ,           m*y - 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由c3
//
//				point C5 = { m*0.5*x + n * x + a - 0.5*sqrt(3)*width*(i - 1) + sqrt(3)*offset - offset,    m*y - 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由c3
//
//
//
//
//				tripoint.push_back(trans(E3, x0, y0)); tripoint.push_back(trans(E1, x0, y0));
//				tripoint.push_back(trans(E1, x0, y0)); tripoint.push_back(trans(B5, x0, y0));
//				tripoint.push_back(trans(B5, x0, y0)); tripoint.push_back(trans(B1, x0, y0));
//				tripoint.push_back(trans(B1, x0, y0)); tripoint.push_back(trans(A1, x0, y0));
//				tripoint.push_back(trans(A1, x0, y0)); tripoint.push_back(trans(A5, x0, y0));
//				tripoint.push_back(trans(A5, x0, y0)); tripoint.push_back(trans(D1, x0, y0));
//				tripoint.push_back(trans(D1, x0, y0)); tripoint.push_back(trans(D3, x0, y0));
//				tripoint.push_back(trans(D3, x0, y0)); tripoint.push_back(trans(D2, x0, y0));
//				tripoint.push_back(trans(D2, x0, y0)); tripoint.push_back(trans(A4, x0, y0));
//				tripoint.push_back(trans(A4, x0, y0)); tripoint.push_back(trans(A2, x0, y0));
//				tripoint.push_back(trans(A2, x0, y0)); tripoint.push_back(trans(C2, x0, y0));
//				tripoint.push_back(trans(C2, x0, y0)); tripoint.push_back(trans(C4, x0, y0));
//				tripoint.push_back(trans(C4, x0, y0)); tripoint.push_back(trans(F1, x0, y0));
//				tripoint.push_back(trans(F1, x0, y0)); tripoint.push_back(trans(F3, x0, y0));
//				tripoint.push_back(trans(F3, x0, y0)); tripoint.push_back(trans(F2, x0, y0));
//				tripoint.push_back(trans(F2, x0, y0)); tripoint.push_back(trans(C5, x0, y0));
//				tripoint.push_back(trans(C5, x0, y0)); tripoint.push_back(trans(C1, x0, y0));
//				tripoint.push_back(trans(C1, x0, y0)); tripoint.push_back(trans(B2, x0, y0));
//				tripoint.push_back(trans(B2, x0, y0)); tripoint.push_back(trans(B4, x0, y0));
//				tripoint.push_back(trans(B4, x0, y0)); tripoint.push_back(trans(E2, x0, y0));
//				tripoint.push_back(trans(E2, x0, y0)); tripoint.push_back(trans(E3, x0, y0));
//
//				tripoint.push_back(trans(E3, x0, y0)); tripoint.push_back(trans(B3, x0, y0));
//				tripoint.push_back(trans(B3, x0, y0)); tripoint.push_back(trans(A3, x0, y0));
//				tripoint.push_back(trans(A3, x0, y0)); tripoint.push_back(trans(D3, x0, y0));
//				tripoint.push_back(trans(A3, x0, y0)); tripoint.push_back(trans(C3, x0, y0));
//				tripoint.push_back(trans(C3, x0, y0)); tripoint.push_back(trans(F3, x0, y0));
//				tripoint.push_back(trans(C3, x0, y0)); tripoint.push_back(trans(B3, x0, y0));
//
//				tripoint.push_back(trans(B, x0, y0)); tripoint.push_back(trans(A, x0, y0));
//				tripoint.push_back(trans(A, x0, y0)); tripoint.push_back(trans(C, x0, y0));
//				tripoint.push_back(trans(C, x0, y0)); tripoint.push_back(trans(B, x0, y0));
//
//
//
//			}
//			n = 0;
//		}
//		break;
//	}
//	case 4:
//	{
//		i = i - 2 * sqrt(3)*0.333*a / width;
//		x0 = -50;
//		y0 = -2 * offset + y;
//		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
//		{
//			for (n; n < 170 / a; n++)
//			{
//
//				point A = { m*0.5*x + n * x + 0.5*a ,               m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a };
//			
//				point D3 = { m*0.5*x + n * x + 0.5*a ,              m*y - 0.5*sqrt(3)*a - 2 * offset };//A
//
//				point D1 = { m*0.5*x + n * x + 0.5*a - offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3
//
//				point D2 = { m*0.5*x + n * x + 0.5*a + offset,      m*y - 0.5*sqrt(3)*a - 2 * offset + 0.333*sqrt(3)*offset };//D3
//
//				point A3 = { m*0.5*x + n * x + 0.5*a ,              m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset }; //A
//
//				point A1 = { m*0.5*x + n * x + 0.5*a - sqrt(3)*offset ,     m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + offset }; //由A3推导出
//
//				point A2 = { m*0.5*x + n * x + 0.5*a + sqrt(3)*offset,      m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + offset }; //由A3推导出
//
//				point A4 = { m*0.5*x + n * x + 0.5*a + offset ,             m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出
//
//				point A5 = { m*0.5*x + n * x + 0.5*a - offset,              m*y - width * (i - 1) + sqrt(3)*0.333*a - sqrt(3)*0.167*a - 2 * offset + 0.333*sqrt(3)*offset }; //由A3推导出
//
//
//				point B = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) , m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point E3 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset };
//
//				point E1 = { m*0.5*x + n * x + 0 - sqrt(3)*offset,            m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset };//e3
//
//				point E2 = { m*0.5*x + n * x + 0 - sqrt(3)*offset + offset,   m*y - 0 + offset + 0.333*sqrt(3)*offset };//e3
//
//				point B3 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset };
//
//				point B1 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 2 * offset };//由B3
//
//				point B2 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) ,                               m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + 2 * offset }; //由B
//
//				point B4 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset + offset ,     m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由B3
//
//				point B5 = { m*0.5*x + n * x + a - sqrt(3)*0.5*width*(i - 1) - sqrt(3)*offset ,              m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由B3
//
//
//
//				point C = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,        m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) };
//
//				point F3 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset };
//
//				point F1 = { m*0.5*x + n * x + a + sqrt(3)*offset ,              m*y - 0 + offset - 0.333 * 2 * sqrt(3)*offset }; //由f3
//
//				point F2 = { m*0.5*x + n * x + a + sqrt(3)*offset - offset,      m*y - 0 + offset + 0.333*sqrt(3)*offset };//由f3
//
//				point C3 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset,             m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset };
//
//				point C1 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) ,                             m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + offset }; //由c
//
//				point C2 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset ,            m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 2 * offset };//由c3
//
//				point C4 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset  ,           m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset - 0.333 * 2 * sqrt(3)*offset }; //由c3
//
//				point C5 = { m*0.5*x + n * x + sqrt(3)*0.5*width*(i - 1) + sqrt(3)*offset - offset,    m*y - sqrt(3) * 0.333 * a + 0.5*width * (i - 1) + offset + 0.333*sqrt(3)*offset };//由c3
//
//
//				tripoint.push_back(trans(E3, x0, y0)); tripoint.push_back(trans(E1, x0, y0));
//				tripoint.push_back(trans(E1, x0, y0)); tripoint.push_back(trans(B5, x0, y0));
//				tripoint.push_back(trans(B5, x0, y0)); tripoint.push_back(trans(B1, x0, y0));
//				tripoint.push_back(trans(B1, x0, y0)); tripoint.push_back(trans(A1, x0, y0));
//				tripoint.push_back(trans(A1, x0, y0)); tripoint.push_back(trans(A5, x0, y0));
//				tripoint.push_back(trans(A5, x0, y0)); tripoint.push_back(trans(D1, x0, y0));
//				tripoint.push_back(trans(D1, x0, y0)); tripoint.push_back(trans(D3, x0, y0));
//				tripoint.push_back(trans(D3, x0, y0)); tripoint.push_back(trans(D2, x0, y0));
//				tripoint.push_back(trans(D2, x0, y0)); tripoint.push_back(trans(A4, x0, y0));
//				tripoint.push_back(trans(A4, x0, y0)); tripoint.push_back(trans(A2, x0, y0));
//				tripoint.push_back(trans(A2, x0, y0)); tripoint.push_back(trans(C2, x0, y0));
//				tripoint.push_back(trans(C2, x0, y0)); tripoint.push_back(trans(C4, x0, y0));
//				tripoint.push_back(trans(C4, x0, y0)); tripoint.push_back(trans(F1, x0, y0));
//				tripoint.push_back(trans(F1, x0, y0)); tripoint.push_back(trans(F3, x0, y0));
//				tripoint.push_back(trans(F3, x0, y0)); tripoint.push_back(trans(F2, x0, y0));
//				tripoint.push_back(trans(F2, x0, y0)); tripoint.push_back(trans(C5, x0, y0));
//				tripoint.push_back(trans(C5, x0, y0)); tripoint.push_back(trans(C1, x0, y0));
//				tripoint.push_back(trans(C1, x0, y0)); tripoint.push_back(trans(B2, x0, y0));
//				tripoint.push_back(trans(B2, x0, y0)); tripoint.push_back(trans(B4, x0, y0));
//				tripoint.push_back(trans(B4, x0, y0)); tripoint.push_back(trans(E2, x0, y0));
//				tripoint.push_back(trans(E2, x0, y0)); tripoint.push_back(trans(E3, x0, y0));
//
//				tripoint.push_back(trans(E3, x0, y0)); tripoint.push_back(trans(B3, x0, y0));
//				tripoint.push_back(trans(B3, x0, y0)); tripoint.push_back(trans(A3, x0, y0));
//				tripoint.push_back(trans(A3, x0, y0)); tripoint.push_back(trans(D3, x0, y0));
//				tripoint.push_back(trans(A3, x0, y0)); tripoint.push_back(trans(C3, x0, y0));
//				tripoint.push_back(trans(C3, x0, y0)); tripoint.push_back(trans(F3, x0, y0));
//				tripoint.push_back(trans(C3, x0, y0)); tripoint.push_back(trans(B3, x0, y0));
//
//				tripoint.push_back(trans(B, x0, y0)); tripoint.push_back(trans(A, x0, y0));
//				tripoint.push_back(trans(A, x0, y0)); tripoint.push_back(trans(C, x0, y0));
//				tripoint.push_back(trans(C, x0, y0)); tripoint.push_back(trans(B, x0, y0));
//
//			}
//			n = 0;
//		}
//		break;
//	}
//
//	default: printf("有问题");
//		break;
//	}
//
//}

void lines()
{
	glColor3f(1.0,0.0,0.0);
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

	gluLookAt(0+xs, 0+ys, 60+zs , 0+xs, 0+ys, 0, 0, 1, 0);
	//glTranslatef(0.0f, 0.0f, -1.0f);	//平移
	//glRotatef(rquad, 1.0f, 0.0f, 0.0f);	//旋转一个角度
	ColorCube();
	lines();

	glColor3f(1.0,0.0,0.0);
	glPointSize(5);

	glBegin(GL_POINTS);
	//glVertex3f(0,0,0);
	//glVertex3f(-50, 0, 1);
	glVertex3f(60, 60, 60);
	glEnd();
	glPopMatrix();

	//rquad -= 0.15f;	//修改立方体的旋转角度
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
	//滚轮事件
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
		sy+=10 ;
		glutPostRedisplay();
		break;
	case 's':
		sy-= 10;
		glutPostRedisplay();
		break;
	case 'a':
		sx-=10;
		glutPostRedisplay();
		break;
	case 'd':
		sx+=10;
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
