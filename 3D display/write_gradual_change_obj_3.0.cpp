//这一次，上端的小三角形结合了前两个版本，1.0保证了每天边的宽度都一样，2.0保证了最后是完美三角形网格，
//所以要结合起来。上面的小三角形用1.0在2.0的下面，下面的大三角形就用2.0的。
#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>

using namespace std;

struct point { GLfloat x, y, z; };

void main()
{
	FILE* fp;

	errno_t err;     //判断此文件流是否存在 存在返回1

	err = fopen_s(&fp, "gradual_change_a20t1_50.obj", "a"); //若return 1 , 则将指向这个文件的文件流给fp1

	float a = 20;                       //三角形边长
	float t = 1.0;                     //壳厚
	float h = 40;
	//float h = 0.5*sqrt(3)*a - t;                     //盒子的高度
	//if (h >= 0.5*sqrt(3)*a - t)
	//	printf("可打印");
	//else
	//	printf("不可打印");
	int m0 = 50, n0 = 50;            //m列数（一行几个），n行数（有几行），l有几层
	float x = a + sqrt(3)*t, y = 0.5*sqrt(3)* a + 1.5 * t;//偏移值 

	int r = 0;//点数计数器

	for (int n = 0; n < n0; n++)
	{
		for (int m = 0; m < m0; m++)
		{
			point A1 = { 0.00 + m * x + n * 0.5*x,                         0.00 + n * y,                   (h*t) / (0.25*sqrt(3)*a) };
			point B2 = { 0.00 + m * x + n * 0.5*x,                         0.00 + n * y,                    h - t };
			point C3 = { 0.25*a - 0.333*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - t + n * y,      h - t };
			point D4 = { 0.5*a - 2 * 0.333*sqrt(3)*t + m * x + n * 0.5*x,  0 + n * y,                       h - t };

			point E5 = { a + m * x + n * 0.5*x,                            0.00 + n * y,                   (h*t) / (0.25*sqrt(3)*a) };
			point F6 = { a + m * x + n * 0.5*x,                            0.00 + n * y,                    h - t };
			point G7 = { 0.75*a + 0.333*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - t + n * y,      h - t };
			point H8 = { 0.5*a + 2 * 0.333*sqrt(3)*t + m * x + n * 0.5*x,  0 + n * y,                       h - t };

			point I9 = { 0.5*a + m * x + n * 0.5*x,                        0.5*sqrt(3)*a + n * y,          (h*t) / (0.25*sqrt(3)*a) };
			point J10 = { 0.5*a + m * x + n * 0.5*x,                       0.5*sqrt(3)*a + n * y,           h - t };
			point K11 = { 0.25*a + 0.333*sqrt(3)*t + m * x + n * 0.5*x,    0.25*sqrt(3)*a + t + n * y,      h - t };
			point L12 = { 0.75*a - 0.333*sqrt(3)*t + m * x + n * 0.5*x,    0.25*sqrt(3)*a + t + n * y,      h - t };

			point M13 = { 0.25*a + m * x + n * 0.5*x,                      0.25*sqrt(3)*a + n * y,          h - t };
			point N14 = { 0.75*a + m * x + n * 0.5*x,                      0.25*sqrt(3)*a + n * y,          h - t };
			point O15 = { 0.5*a + m * x + n * 0.5*x,                       0 + n * y,                       h - t };

			point P16 = { 0.00 + m * x + n * 0.5*x,                        0.00 + n * y,                    0 };
			point Q17 = { a + m * x + n * 0.5*x,                           0.00 + n * y,                    0 };
			point R18 = { 0.5*a + m * x + n * 0.5*x,                       0.5*sqrt(3)*a + n * y,           0 };

			//下面的点保证细分后的小三角形是完美三角网格
			point B19 = { 0.00 + m * x + n * 0.5*x,                        0.00 + n * y,                    h };
			point C20 = { 0.25*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - 0.75*t + n * y, h };
			point D21 = { 0.5*a - 0.5*sqrt(3)*t + m * x + n * 0.5*x,       0 + n * y,                       h };

			point F22 = { a + m * x + n * 0.5*x,                           0.00 + n * y,                    h };
			point G23 = { 0.75*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - 0.75*t + n * y, h };
			point H24 = { 0.5*a + 0.5*sqrt(3)*t + m * x + n * 0.5*x,       0 + n * y,                       h };

			point J25 = { 0.5*a + m * x + n * 0.5*x,                       0.5*sqrt(3)*a + n * y,           h };
			point K26 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a + 0.75*t + n * y, h };
			point L27 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a + 0.75*t + n * y, h };

			point M28 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - 0.25*t + n * y, h };
			point N29 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x,     0.25*sqrt(3)*a - 0.25*t + n * y, h };
			point O30 = { 0.5*a + m * x + n * 0.5*x,                       0.5*t + n * y,                   h };


			
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
			//新加的第二层，为了变成完美三角网格
			fprintf(fp, "v %f %f %f\n", B19.x, B19.y, B19.z);
			fprintf(fp, "v %f %f %f\n", C20.x, C20.y, C20.z);
			fprintf(fp, "v %f %f %f\n", D21.x, D21.y, D21.z);

			fprintf(fp, "v %f %f %f\n", F22.x, F22.y, F22.z);
			fprintf(fp, "v %f %f %f\n", G23.x, G23.y, G23.z);
			fprintf(fp, "v %f %f %f\n", H24.x, H24.y, H24.z);

			fprintf(fp, "v %f %f %f\n", J25.x, J25.y, J25.z);
			fprintf(fp, "v %f %f %f\n", K26.x, K26.y, K26.z);
			fprintf(fp, "v %f %f %f\n", L27.x, L27.y, L27.z);

			fprintf(fp, "v %f %f %f\n", M28.x, M28.y, M28.z);
			fprintf(fp, "v %f %f %f\n", N29.x, N29.y, N29.z);
			fprintf(fp, "v %f %f %f\n", O30.x, O30.y, O30.z);


			fprintf(fp, "f %d %d %d\n", 19 + r, 20 + r, 21 + r);
			fprintf(fp, "f %d %d %d %d\n", 19 + r, 21 + r, 4 + r, 2 + r);
			fprintf(fp, "f %d %d %d %d\n", 21 + r, 20 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d %d\n", 20 + r, 19 + r, 2 + r, 3 + r);
			//fprintf(fp, "f %d %d %d\n", 2 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 4 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 3 + r, 2 + r);

			fprintf(fp, "f %d %d %d\n", 24 + r, 23 + r, 22 + r);
			fprintf(fp, "f %d %d %d %d\n", 24 + r, 22 + r, 6 + r, 8 + r);
			fprintf(fp, "f %d %d %d %d\n", 22 + r, 23 + r, 7 + r, 6 + r);
			fprintf(fp, "f %d %d %d %d\n", 23 + r, 24 + r, 8 + r, 7 + r);
			//fprintf(fp, "f %d %d %d\n", 6 + r, 8 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 6 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 8 + r, 6 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 7 + r, 8 + r);

			fprintf(fp, "f %d %d %d\n", 25 + r, 27 + r, 26 + r);
			fprintf(fp, "f %d %d %d %d\n", 26 + r, 27 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d %d\n", 27 + r, 25 + r, 10 + r, 12 + r);
			fprintf(fp, "f %d %d %d %d\n", 25 + r, 26 + r, 11 + r, 10 + r);
			//fprintf(fp, "f %d %d %d\n", 10 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 9 + r, 12 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 11 + r, 9 + r);
			fprintf(fp, "f %d %d %d\n", 11 + r, 12 + r, 9 + r);

			fprintf(fp, "f %d %d %d\n", 28 + r, 29 + r, 30 + r);
			fprintf(fp, "f %d %d %d %d\n", 28 + r, 30 + r, 15 + r, 13 + r);
			fprintf(fp, "f %d %d %d %d\n", 30 + r, 29 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d %d\n", 29 + r, 28 + r, 13 + r, 14 + r);
			//fprintf(fp, "f %d %d %d\n", 13 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 15 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 17 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 14 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 18 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 13 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 16 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 16 + r, 17 + r, 18 + r);


			r += 30;

		}
	}

	for (int n = 0; n < n0 - 1; n++) //x坐标+ 0.5*a + 0.5*sqrt(3)*t， y坐标先取反再 + 0.5*t + 0.5*sqrt(3)*a，z坐标不变
	{
		for (int m = 0; m < m0 - 1; m++)
		{

			point A1 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                         -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                   (h*t) / (0.25*sqrt(3)*a) };
			point B2 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                         -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    h - t };
			point C3 = { 0.25*a - 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - t)+ n * y + 0.5*t + 0.5*sqrt(3)*a,      h - t };
			point D4 = { 0.5*a - 2 * 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,  -(0)+ n * y + 0.5*t + 0.5*sqrt(3)*a,                       h - t };

			point E5 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                            -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                   (h*t) / (0.25*sqrt(3)*a) };
			point F6 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                            -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    h - t };
			point G7 = { 0.75*a + 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - t) + n * y + 0.5*t + 0.5*sqrt(3)*a,      h - t };
			point H8 = { 0.5*a + 2 * 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,  -(0) + n * y + 0.5*t + 0.5*sqrt(3)*a,                       h - t };

			point I9 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                        -(0.5*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,          (h*t) / (0.25*sqrt(3)*a) };
			point J10 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0.5*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,           h - t };
			point K11 = { 0.25*a + 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,    -(0.25*sqrt(3)*a + t) + n * y + 0.5*t + 0.5*sqrt(3)*a,      h - t };
			point L12 = { 0.75*a - 0.333*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,    -(0.25*sqrt(3)*a + t) + n * y + 0.5*t + 0.5*sqrt(3)*a,      h - t };

			point M13 = { 0.25*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                      -(0.25*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,          h - t };
			point N14 = { 0.75*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                      -(0.25*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,          h - t };
			point O15 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0) + n * y + 0.5*t + 0.5*sqrt(3)*a,                       h - t };

			point P16 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                        -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    0 };
			point Q17 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                           -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    0 };
			point R18 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0.5*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,           0 };

			//下面的点保证细分后的小三角形是完美三角网格
			point B19 = { 0.00 + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                        -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    h };
			point C20 = { 0.25*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - 0.75*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };
			point D21 = { 0.5*a - 0.5*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,       -(0) + n * y + 0.5*t + 0.5*sqrt(3)*a,                       h };

			point F22 = { a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                           -(0.00) + n * y + 0.5*t + 0.5*sqrt(3)*a,                    h };
			point G23 = { 0.75*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - 0.75*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };
			point H24 = { 0.5*a + 0.5*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,       -(0) + n * y + 0.5*t + 0.5*sqrt(3)*a,                       h };

			point J25 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0.5*sqrt(3)*a) + n * y + 0.5*t + 0.5*sqrt(3)*a,           h };
			point K26 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a + 0.75*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };
			point L27 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a + 0.75*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };

			point M28 = { 0.25*a + 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - 0.25*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };
			point N29 = { 0.75*a - 0.25*sqrt(3)*t + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,     -(0.25*sqrt(3)*a - 0.25*t) + n * y + 0.5*t + 0.5*sqrt(3)*a, h };
			point O30 = { 0.5*a + m * x + n * 0.5*x + 0.5*a + 0.5*sqrt(3)*t,                       -(0.5*t) + n * y + 0.5*t + 0.5*sqrt(3)*a,                   h };



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
			//新加的第二层，为了变成完美三角网格
			fprintf(fp, "v %f %f %f\n", B19.x, B19.y, B19.z);
			fprintf(fp, "v %f %f %f\n", C20.x, C20.y, C20.z);
			fprintf(fp, "v %f %f %f\n", D21.x, D21.y, D21.z);

			fprintf(fp, "v %f %f %f\n", F22.x, F22.y, F22.z);
			fprintf(fp, "v %f %f %f\n", G23.x, G23.y, G23.z);
			fprintf(fp, "v %f %f %f\n", H24.x, H24.y, H24.z);

			fprintf(fp, "v %f %f %f\n", J25.x, J25.y, J25.z);
			fprintf(fp, "v %f %f %f\n", K26.x, K26.y, K26.z);
			fprintf(fp, "v %f %f %f\n", L27.x, L27.y, L27.z);

			fprintf(fp, "v %f %f %f\n", M28.x, M28.y, M28.z);
			fprintf(fp, "v %f %f %f\n", N29.x, N29.y, N29.z);
			fprintf(fp, "v %f %f %f\n", O30.x, O30.y, O30.z);


			fprintf(fp, "f %d %d %d\n", 19 + r, 20 + r, 21 + r);
			fprintf(fp, "f %d %d %d %d\n", 19 + r, 21 + r, 4 + r, 2 + r);
			fprintf(fp, "f %d %d %d %d\n", 21 + r, 20 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d %d\n", 20 + r, 19 + r, 2 + r, 3 + r);
			//fprintf(fp, "f %d %d %d\n", 2 + r, 3 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 2 + r, 4 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 4 + r, 3 + r);
			fprintf(fp, "f %d %d %d\n", 1 + r, 3 + r, 2 + r);

			fprintf(fp, "f %d %d %d\n", 24 + r, 23 + r, 22 + r);
			fprintf(fp, "f %d %d %d %d\n", 24 + r, 22 + r, 6 + r, 8 + r);
			fprintf(fp, "f %d %d %d %d\n", 22 + r, 23 + r, 7 + r, 6 + r);
			fprintf(fp, "f %d %d %d %d\n", 23 + r, 24 + r, 8 + r, 7 + r);
			//fprintf(fp, "f %d %d %d\n", 6 + r, 8 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 6 + r, 7 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 8 + r, 6 + r);
			fprintf(fp, "f %d %d %d\n", 5 + r, 7 + r, 8 + r);

			fprintf(fp, "f %d %d %d\n", 25 + r, 27 + r, 26 + r);
			fprintf(fp, "f %d %d %d %d\n", 26 + r, 27 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d %d\n", 27 + r, 25 + r, 10 + r, 12 + r);
			fprintf(fp, "f %d %d %d %d\n", 25 + r, 26 + r, 11 + r, 10 + r);
			//fprintf(fp, "f %d %d %d\n", 10 + r, 12 + r, 11 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 9 + r, 12 + r);
			fprintf(fp, "f %d %d %d\n", 10 + r, 11 + r, 9 + r);
			fprintf(fp, "f %d %d %d\n", 11 + r, 12 + r, 9 + r);

			fprintf(fp, "f %d %d %d\n", 28 + r, 29 + r, 30 + r);
			fprintf(fp, "f %d %d %d %d\n", 28 + r, 30 + r, 15 + r, 13 + r);
			fprintf(fp, "f %d %d %d %d\n", 30 + r, 29 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d %d\n", 29 + r, 28 + r, 13 + r, 14 + r);
			//fprintf(fp, "f %d %d %d\n", 13 + r, 14 + r, 15 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 15 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 17 + r, 16 + r);
			fprintf(fp, "f %d %d %d\n", 15 + r, 14 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 18 + r, 17 + r);
			fprintf(fp, "f %d %d %d\n", 14 + r, 13 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 13 + r, 16 + r, 18 + r);
			fprintf(fp, "f %d %d %d\n", 16 + r, 17 + r, 18 + r);


			r += 30;
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