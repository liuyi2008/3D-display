//与1.0相比，开头和结尾是完美的三角网格
#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>

using namespace std;

struct point { GLfloat x, y, z; };

void main()
{
	FILE* fp;

	errno_t err;     //判断此文件流是否存在 存在返回1

	err = fopen_s(&fp, "gradual_change_a20t1_100.obj", "a"); //若return 1 , 则将指向这个文件的文件流给fp1

	float a = 20;                       //三角形边长
	float t = 1.0;                     //壳厚
	float h = 0.5*sqrt(3)*a - t;                     //盒子的高度
	//if (h >= 0.5*sqrt(3)*a - t)
	//	printf("可打印");
	//else
	//	printf("不可打印");
	int m0 = 100, n0 = 100;            //m列数（一行几个），n行数（有几行），l有几层
	float x = a + sqrt(3)*t, y = 0.5*sqrt(3)* a + 1.5 * t;//偏移值 

	int r = 0;//点数计数器

	for (int n = 0; n < n0; n++)
	{
		for (int m = 0; m < m0; m++)
		{
			point A1 = { 0.00 + m * x + n * 0.5*x,                     0.00 + n * y,                   (h*t)/(0.25*sqrt(3)*a) };
			point B2 = { 0.00 + m * x + n * 0.5*x,                     0.00 + n * y,                    h };
			point C3 = { 0.25*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x,  0.25*sqrt(3)*a - 0.75*t + n * y, h };
			point D4 = { 0.5*a - 0.5*sqrt(3)*t + m * x + n * 0.5*x,    0 + n * y,                       h };

			point E5 = { a + m * x + n * 0.5*x,                        0.00 + n * y,                   (h*t) / (0.25*sqrt(3)*a) };
			point F6 = { a + m * x + n * 0.5*x,                        0.00 + n * y,                    h };
			point G7 = { 0.75*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x,  0.25*sqrt(3)*a - 0.75*t + n * y, h };
			point H8 = { 0.5*a + 0.5*sqrt(3)*t + m * x + n * 0.5*x,    0 + n * y,                       h };

			point I9 = { 0.5*a + m * x + n * 0.5*x,                    0.5*sqrt(3)*a + n * y,          (h*t) / (0.25*sqrt(3)*a) };
			point J10 = { 0.5*a + m * x + n * 0.5*x,                   0.5*sqrt(3)*a + n * y,           h };
			point K11 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x, 0.25*sqrt(3)*a + 0.75*t + n * y, h };
			point L12 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x, 0.25*sqrt(3)*a + 0.75*t + n * y, h };

			point M13 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x, 0.25*sqrt(3)*a - 0.25*t + n * y, h };
			point N14 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x, 0.25*sqrt(3)*a - 0.25*t + n * y, h };
			point O15 = { 0.5*a + m * x + n * 0.5*x,                   0.5*t + n * y,                   h };

			point P16 = { 0.00 + m * x + n * 0.5*x,                    0.00 + n * y,                    0 };
			point Q17 = { a + m * x + n * 0.5*x,                       0.00 + n * y,                    0 };
			point R18 = { 0.5*a + m * x + n * 0.5*x,                   0.5*sqrt(3)*a + n * y,           0 };


			fprintf(fp, "v %f %f %f\n", A1.x, A1.y, A1.z);
			fprintf(fp, "v %f %f %f\n", B2.x, B2.y, B2.z);
			fprintf(fp, "v %f %f %f\n", C3.x, C3.y, C3.z);
			fprintf(fp, "v %f %f %f\n", D4.x, D4.y, D4.z);
			fprintf(fp, "v %f %f %f\n", E5.x, E5.y, E5.z);
			fprintf(fp, "v %f %f %f\n", F6.x, F6.y, F6.z);
			fprintf(fp, "v %f %f %f\n", G7.x, G7.y, G7.z);
			fprintf(fp, "v %f %f %f\n", H8.x, H8.y, H8.z);
			fprintf(fp, "v %f %f %f\n", I9.x, I9.y, I9.z);
			fprintf(fp, "v %f %f %f\n", J10.x, J10.y, J10.z);
			fprintf(fp, "v %f %f %f\n", K11.x, K11.y, K11.z);
			fprintf(fp, "v %f %f %f\n", L12.x, L12.y, L12.z);
			fprintf(fp, "v %f %f %f\n", M13.x, M13.y, M13.z);
			fprintf(fp, "v %f %f %f\n", N14.x, N14.y, N14.z);
			fprintf(fp, "v %f %f %f\n", O15.x, O15.y, O15.z);
			fprintf(fp, "v %f %f %f\n", P16.x, P16.y, P16.z);
			fprintf(fp, "v %f %f %f\n", Q17.x, Q17.y, Q17.z);
			fprintf(fp, "v %f %f %f\n", R18.x, R18.y, R18.z);


			fprintf(fp, "f %d %d %d\n", 2 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 4 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 3 + r, 2 + r);

			fprintf(fp, "f %d %d %d\n", 6 + r, 8 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 6 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 8 + r, 6 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 7 + r, 8 + r);

			fprintf(fp, "f %d %d %d\n", 10 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 9 + r, 12 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 11 + r, 9 + r);
			fprintf(fp, "f %d %d %d\n", 11 + r, 12 + r, 9 + r);


			fprintf(fp, "f %d %d %d\n", 13 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 15 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 17 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 14 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 18 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 13 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 16 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 16 + r, 17 + r, 18 + r);
			

			r += 18;

		}
	}

	for (int n = 0; n < n0 - 1; n++)
	{
		for (int m = 0; m < m0 - 1; m++)
		{

			point A1 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                     -(0.00) + 0.5*t + 0.5*sqrt(3)*a + n * y,                    (h*t) / (0.25*sqrt(3)*a) };
			point B2 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                     -(0.00) + 0.5*t + 0.5*sqrt(3)*a + n * y,                    h };
			point C3 = { 0.25*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,  -(0.25*sqrt(3)*a - 0.75*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };
			point D4 = { 0.5*a - 0.5*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,    -(0) + 0.5*t + 0.5*sqrt(3)*a + n * y,                       h };

			point E5 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                        -(0.00) + 0.5*t + 0.5*sqrt(3)*a + n * y,                    (h*t) / (0.25*sqrt(3)*a) };
			point F6 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                        -(0.00) + 0.5*t + 0.5*sqrt(3)*a + n * y,                    h };
			point G7 = { 0.75*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,  -(0.25*sqrt(3)*a - 0.75*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };
			point H8 = { 0.5*a + 0.5*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,    -(0) + 0.5*t + 0.5*sqrt(3)*a + n * y,                       h };

			point I9 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                    -(0.5*sqrt(3)*a) + 0.5*t + 0.5*sqrt(3)*a + n * y,          (h*t) / (0.25*sqrt(3)*a) };
			point J10 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                   -(0.5*sqrt(3)*a) + 0.5*t + 0.5*sqrt(3)*a + n * y,           h };
			point K11 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t, -(0.25*sqrt(3)*a + 0.75*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };
			point L12 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t, -(0.25*sqrt(3)*a + 0.75*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };

			point M13 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t, -(0.25*sqrt(3)*a - 0.25*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };
			point N14 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t, -(0.25*sqrt(3)*a - 0.25*t) + 0.5*t + 0.5*sqrt(3)*a + n * y, h };
			point O15 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                   -(0.5*t) + 0.5*t + 0.5*sqrt(3)*a + n * y,                   h };

			point P16 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                    -(0)+0.5*t + 0.5*sqrt(3)*a + n * y,                         0 };
			point Q17 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0) + 0.5*t + 0.5*sqrt(3)*a + n * y,                       0 };
			point R18 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                   -(0.5*sqrt(3)*a) + 0.5*t + 0.5*sqrt(3)*a + n * y,           0 };
		;


			fprintf(fp, "v %f %f %f\n", A1.x, A1.y, A1.z);
			fprintf(fp, "v %f %f %f\n", B2.x, B2.y, B2.z);
			fprintf(fp, "v %f %f %f\n", C3.x, C3.y, C3.z);
			fprintf(fp, "v %f %f %f\n", D4.x, D4.y, D4.z);
			fprintf(fp, "v %f %f %f\n", E5.x, E5.y, E5.z);
			fprintf(fp, "v %f %f %f\n", F6.x, F6.y, F6.z);
			fprintf(fp, "v %f %f %f\n", G7.x, G7.y, G7.z);
			fprintf(fp, "v %f %f %f\n", H8.x, H8.y, H8.z);
			fprintf(fp, "v %f %f %f\n", I9.x, I9.y, I9.z);
			fprintf(fp, "v %f %f %f\n", J10.x, J10.y, J10.z);
			fprintf(fp, "v %f %f %f\n", K11.x, K11.y, K11.z);
			fprintf(fp, "v %f %f %f\n", L12.x, L12.y, L12.z);
			fprintf(fp, "v %f %f %f\n", M13.x, M13.y, M13.z);
			fprintf(fp, "v %f %f %f\n", N14.x, N14.y, N14.z);
			fprintf(fp, "v %f %f %f\n", O15.x, O15.y, O15.z);
			fprintf(fp, "v %f %f %f\n", P16.x, P16.y, P16.z);
			fprintf(fp, "v %f %f %f\n", Q17.x, Q17.y, Q17.z);
			fprintf(fp, "v %f %f %f\n", R18.x, R18.y, R18.z);


			fprintf(fp, "f %d %d %d\n", 2 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 4 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 3 + r, 2 + r);

			fprintf(fp, "f %d %d %d\n", 6 + r, 8 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 6 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 8 + r, 6 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 7 + r, 8 + r);

			fprintf(fp, "f %d %d %d\n", 10 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 9 + r, 12 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 11 + r, 9 + r);
			fprintf(fp, "f %d %d %d\n", 11 + r, 12 + r, 9 + r);


			fprintf(fp, "f %d %d %d\n", 13 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 15 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 17 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 14 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 18 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 13 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 16 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 16 + r, 17 + r, 18 + r);

			r += 18;
		}
	}


	fprintf(fp, "v %f %f %f\n", -t, -t - 0.5*a*0.33*sqrt(3), h + t);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, -t - 0.5*a*0.33*sqrt(3), h + t);
	fprintf(fp, "v %f %f %f\n", -t, y*n0 + t, h + t);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, y*n0 + t, h + t);

	fprintf(fp, "v %f %f %f\n", -t, y*n0 + t, -t);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, y*n0 + t, -t);
	fprintf(fp, "v %f %f %f\n", -t, -t - 0.5*a*0.33*sqrt(3), -t);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x, -t - 0.5*a*0.33*sqrt(3), -t);

	fprintf(fp, "f %d %d %d %d\n", 1 + r, 2 + r, 4 + r, 3 + r);
	fprintf(fp, "f %d %d %d %d\n", 7 + r, 5 + r, 6 + r, 8 + r);
	fprintf(fp, "f %d %d %d %d\n", 1 + r, 3 + r, 5 + r, 7 + r);
	fprintf(fp, "f %d %d %d %d\n", 8 + r, 6 + r, 4 + r, 2 + r);
	fprintf(fp, "f %d %d %d %d\n", 7 + r, 8 + r, 2 + r, 1 + r);
	fprintf(fp, "f %d %d %d %d\n", 3 + r, 4 + r, 6 + r, 5 + r);

	fclose(fp);

}