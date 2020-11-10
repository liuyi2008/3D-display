#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>

using namespace std;

struct point { GLfloat x, y, z; };

void main()
{
	FILE* fp;

	errno_t err;     //判断此文件流是否存在 存在返回1

	err = fopen_s(&fp, "triangle.obj", "a"); //若return 1 , 则将指向这个文件的文件流给fp1

	float a = 20;                       //三角形边长
	float thickness = 1.0;             //壳厚
	float h = 80;                     //盒子的高度
	int m0 = 10, n0 = 10;            //m列数（一行几个），n行数（有几行），l有几层
	float x = a + sqrt(3)*thickness, y = 0.5*sqrt(3)* a + 1.5 * thickness;//偏移值 

	int r = 0;//点数计数器

	for (int n = 0; n < n0; n++)
	{
		for (int m = 0; m < m0; m++)
		{

			point D2 = { 0.5*a + m * x + n * 0.5*x,   0.5*sqrt(3)*a + n * y,         0 };
			point E3 = { 0.00 + m * x + n * 0.5*x,    0.00 + n * y,                  0 };
			point F4 = { a + m * x + n * 0.5*x,       0.00 + n * y,                  0 };

			point D8 = { 0.5*a + m * x + n * 0.5*x,   0.5*sqrt(3)*a + n * y,         h };
			point E9 = { 0.00 + m * x + n * 0.5*x,    0.00 + n * y,                  h };
			point F10 = { a + m * x + n * 0.5*x,       0.00 + n * y,                 h };



			fprintf(fp, "v %f %f %f\n", D2.x, D2.y, D2.z);
			fprintf(fp, "v %f %f %f\n", E3.x, E3.y, E3.z);
			fprintf(fp, "v %f %f %f\n", F4.x, F4.y, F4.z);
			fprintf(fp, "v %f %f %f\n", D8.x, D8.y, D8.z);
			fprintf(fp, "v %f %f %f\n", E9.x, E9.y, E9.z);
			fprintf(fp, "v %f %f %f\n", F10.x, F10.y, F10.z);


			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 4 + r, 6 + r, 5 + r);
			fprintf(fp, "f %d %d %d %d\n", 5 + r, 6 + r, 3 + r, 2 + r);
			fprintf(fp, "f %d %d %d %d\n", 6 + r, 4 + r, 1 + r, 3 + r);
			fprintf(fp, "f %d %d %d %d\n", 5 + r, 2 + r, 1 + r, 4 + r);

			r += 6;

		}
	}

	for (int n = 0; n < n0 - 1; n++)
	{
		for (int m = 0; m < m0 - 1; m++)
		{

			point D2 = { 0.5 * a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,   0.5*thickness + 0.5*sqrt(3)*a + n * y, 0 };
			point E3 = { a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,         0.5*thickness + n * y ,                0 };
			point F4 = { 1.5 * a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,   0.5*thickness + 0.5*sqrt(3)*a + n * y, 0 };

			point D8 = { 0.5 * a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,   0.5*thickness + 0.5*sqrt(3)*a + n * y, h };
			point E9 = { a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,         0.5*thickness + n * y ,                h };
			point F10 = { 1.5 * a + 0.5*sqrt(3)*thickness + m * x + n * 0.5 * x,  0.5*thickness + 0.5*sqrt(3)*a + n * y, h };


			fprintf(fp, "v %f %f %f\n", D2.x, D2.y, D2.z);
			fprintf(fp, "v %f %f %f\n", E3.x, E3.y, E3.z);
			fprintf(fp, "v %f %f %f\n", F4.x, F4.y, F4.z);
			fprintf(fp, "v %f %f %f\n", D8.x, D8.y, D8.z);
			fprintf(fp, "v %f %f %f\n", E9.x, E9.y, E9.z);
			fprintf(fp, "v %f %f %f\n", F10.x, F10.y, F10.z);


			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 4 + r, 6 + r, 5 + r);
			fprintf(fp, "f %d %d %d %d\n", 5 + r, 6 + r, 3 + r, 2 + r);
			fprintf(fp, "f %d %d %d %d\n", 6 + r, 4 + r, 1 + r, 3 + r);
			fprintf(fp, "f %d %d %d %d\n", 5 + r, 2 + r, 1 + r, 4 + r);

			r += 6;
		}
	}


	fprintf(fp, "v %f %f %f\n", -thickness, -thickness - 0.5*a*0.33*sqrt(3), h + thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, -thickness - 0.5*a*0.33*sqrt(3), h + thickness);
	fprintf(fp, "v %f %f %f\n", -thickness, y*n0 + thickness, h + thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, y*n0 + thickness, h + thickness);

	fprintf(fp, "v %f %f %f\n", -thickness, y*n0 + thickness, -thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, y*n0 + thickness, -thickness);
	fprintf(fp, "v %f %f %f\n", -thickness, -thickness - 0.5*a*0.33*sqrt(3), -thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, -thickness - 0.5*a*0.33*sqrt(3), -thickness);

	fprintf(fp, "f %d %d %d %d\n", 1 + r, 2 + r, 4 + r, 3 + r);
	fprintf(fp, "f %d %d %d %d\n", 7 + r, 5 + r, 6 + r, 8 + r);
	fprintf(fp, "f %d %d %d %d\n", 1 + r, 3 + r, 5 + r, 7 + r);
	fprintf(fp, "f %d %d %d %d\n", 8 + r, 6 + r, 4 + r, 2 + r);
	fprintf(fp, "f %d %d %d %d\n", 7 + r, 8 + r, 2 + r, 1 + r);
	fprintf(fp, "f %d %d %d %d\n", 3 + r, 4 + r, 6 + r, 5 + r);

	fclose(fp);

}