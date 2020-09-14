#include <gl/glut.h>  
#include<math.h>
#include<stdio.h>
#include <vector>

using std::vector;
using namespace std;

struct point { GLfloat x, y, z; };

vector<vector<point> >tripoint;

void writpointcloud()
{
	FILE* fp;

	errno_t err;     //判断此文件流是否存在 存在返回1

	err = fopen_s(&fp, "test pointcloud.txt", "a"); //若return 1 , 则将指向这个文件的文件流给fp1

	double E = 0;

	for (int i = 0; i < tripoint.size(); i++) //每一层 i代表层数
	{
		//for (int j = 1; j < model[i].size(); j += 2)
		//{
		//	fprintf(fp, "%.3f %.3f %.3f\t", model[i][j-1].x, model[i][j-1].y, i*0.2);
		//	fprintf(fp, "%.3f %.3f %.3f\n", model[i][j].x, model[i][j].y, i*0.2);
		//}

		for (int k = 1; k < tripoint[i].size(); k += 2)
		{
			fprintf(fp, "%.3f %.3f %.3f\t", tripoint[i][k - 1].x, tripoint[i][k - 1].y, i*0.1);
			fprintf(fp, "%.3f %.3f %.3f\n", tripoint[i][k].x, tripoint[i][k].y, i*0.1);
		}
	}

	fclose(fp);
}

point normal(point a, point b, point c) //三个点，先求两个向量，再求法向量ab x ac
{
	point ab = { b.x - a.x,b.y - a.y,b.z - a.z };//向量
	point ac = { c.x - a.x,c.y - a.y,c.z - a.z };//向量

	float x1 = ab.x;
	float y1 = ab.y;
	float z1 = ab.z;

	float x2 = ac.x;
	float y2 = ac.y;
	float z2 = ac.z;

	return { y1*z2 - y2 * z1,x2*z1 - x1 * z2,x1*y2 - x2 * y1 };
}

void main()
{
	//point a = {20.00,11.5470,20.00};
	//point b = { 20.00,0.00,30.00 };
	//point c = { 10.00,17.3205,30.00 };
	//point d;
	//d = normal(a, b, c);
	//printf("x=%f,y=%f,z=%f\n", d.x, d.y, d.z);
	FILE* fp;

	errno_t err;     //判断此文件流是否存在 存在返回1

	err = fopen_s(&fp, "test obj.txt", "a"); //若return 1 , 则将指向这个文件的文件流给fp1

	//fprintf(fp, "vn -1.7320 1.0000 -1.1154\n");
	//fprintf(fp, "vn -1.0000 0.0000 0.0000\n");
	//fprintf(fp, "vn -1.1547 2.000 0.0000\n");
	//fprintf(fp, "vn -1.7320 1.000 1.1154\n");

	//fprintf(fp, "vn 0.0000 -2.0000 -1.1547\n");
	//fprintf(fp, "vn 1.1547 -2.0000 0.0000\n");
	//fprintf(fp, "vn -1.1547 -2.0000 0.0000\n");
	//fprintf(fp, "vn 0.0000 -2.0000 1.1547\n");

	//fprintf(fp, "vn 1.7320 1.0000 -1.1154\n");
	//fprintf(fp, "vn 1.1547 2.0000 0.0000\n");
	//fprintf(fp, "vn 1.0000 0.0000 0.0000\n");
	//fprintf(fp, "vn 1.7320 1.0000 1.1154\n");

	//fprintf(fp, "vn -1.7320 -1.0000 -1.1154\n");//13
	//fprintf(fp, "vn 1.7320 -1.0000 -1.1154\n");//14
	//fprintf(fp, "vn 0.0000 2.0000 -1.1547\n");//15
	//fprintf(fp, "vn -1.7320 -1.0000 1.1154\n");//16
	//fprintf(fp, "vn 1.7320 -1.0000 1.1154\n");//17
	//fprintf(fp, "vn 0.0000 2.0000 1.1547\n");//18
	//以上，于想要的
	//以下，向量向里空心的
	fprintf(fp, "vn 1.7320 -1.0000 1.1154\n");
	fprintf(fp, "vn 1.0000 0.0000 0.0000\n");
	fprintf(fp, "vn 1.1547 -2.000 0.0000\n");
	fprintf(fp, "vn 1.7320 -1.000 -1.1154\n");

	fprintf(fp, "vn 0.0000 2.0000 1.1547\n");
	fprintf(fp, "vn -1.1547 2.0000 0.0000\n");
	fprintf(fp, "vn 1.1547 2.0000 0.0000\n");
	fprintf(fp, "vn 0.0000 2.0000 -1.1547\n");

	fprintf(fp, "vn -1.7320 -1.0000 1.1154\n");
	fprintf(fp, "vn -1.1547 -2.0000 0.0000\n");
	fprintf(fp, "vn -1.0000 0.0000 0.0000\n");
	fprintf(fp, "vn -1.7320 -1.0000 -1.1154\n");

	fprintf(fp, "vn 1.7320 1.0000 1.1154\n");//13
	fprintf(fp, "vn -1.7320 1.0000 1.1154\n");//14
	fprintf(fp, "vn 0.0000 -2.0000 1.1547\n");//15
	fprintf(fp, "vn 1.7320 1.0000 -1.1154\n");//16
	fprintf(fp, "vn -1.7320 1.0000 -1.1154\n");//17
	fprintf(fp, "vn 0.0000 -2.0000 -1.1547\n");//18

	float a = 20.0;//三角形边长
	float h = 0.5*a*0.333*sqrt(3) * 4;//cell高 
				                      //a、h、角度,知二得三 
	                                  //45°时：h = 0.5*a*0.333*sqrt(3)*4

	int m = 0, n = 0, l = 0; //计数器
	int m0 = 5, n0 = 5, l0 = 5;//m列数（一行几个），n行数（有几行），l有几层

	float thickness = 0.5;
	float x = a + thickness, y = 0.5*sqrt(3)*(a + thickness) , z = h + thickness;//偏移值 

	int r = 0;//点数计数器

	for (l = 0; l < l0; l++)
	{
		for (n = 0; n < n0; n++)
		{
			for (m = 0; m < m0; m++)
			{

				point O1 = { 0.5*a + m * x + n * 0.5*x,   0.5*0.333*sqrt(3)*a + n * y,   0.00 + l * z };

				point D2 = { 0.5*a + m * x + n * 0.5*x,   0.5*sqrt(3)*a + n * y,         0.25*h + l * z };
				point E3 = { 0.00 + m * x + n * 0.5*x,    0.00 + n * y,                  0.25*h + l * z };
				point F4 = { a + m * x + n * 0.5*x,       0.00 + n * y,                  0.25*h + l * z };

				point G5 = { 0.00 + m * x + n * 0.5*x,    a*0.33*sqrt(3) + n * y,         0.5*h + l * z };
				point H6 = { 0.5*a + m * x + n * 0.5*x,   -0.5*0.333*sqrt(3)*a + n * y,   0.5*h + l * z };
				point I7 = { a + m * x + n * 0.5*x,       a*0.33*sqrt(3) + n * y,        0.5*h + l * z };

				point D8 = { 0.5*a + m * x + n * 0.5*x,   0.5*sqrt(3)*a + n * y,          0.75*h + l * z };
				point E9 = { 0.00 + m * x + n * 0.5*x,    0.00 + n * y,                  0.75*h + l * z };
				point F10 = { a + m * x + n * 0.5*x,      0.00 + n * y,                   0.75*h + l * z };

				point O11 = { 0.5*a + m * x + n * 0.5*x,  0.5*0.333*sqrt(3)*a + n * y,   h + l * z };

				fprintf(fp, "v %f %f %f\n", O1.x, O1.y, O1.z);
				fprintf(fp, "v %f %f %f\n", D2.x, D2.y, D2.z);
				fprintf(fp, "v %f %f %f\n", E3.x, E3.y, E3.z);
				fprintf(fp, "v %f %f %f\n", F4.x, F4.y, F4.z);
				fprintf(fp, "v %f %f %f\n", G5.x, G5.y, G5.z);
				fprintf(fp, "v %f %f %f\n", H6.x, H6.y, H6.z);
				fprintf(fp, "v %f %f %f\n", I7.x, I7.y, I7.z);
				fprintf(fp, "v %f %f %f\n", D8.x, D8.y, D8.z);
				fprintf(fp, "v %f %f %f\n", E9.x, E9.y, E9.z);
				fprintf(fp, "v %f %f %f\n", F10.x, F10.y, F10.z);
				fprintf(fp, "v %f %f %f\n", O11.x, O11.y, O11.z);

				fprintf(fp, "f %d//1 %d//1 %d//1\n", 1 + r, 3 + r, 2 + r);
				fprintf(fp, "f %d//9 %d//9 %d//9\n", 1 + r, 2 + r, 4 + r);
				fprintf(fp, "f %d//5 %d//5 %d//5\n", 1 + r, 4 + r, 3 + r);
				fprintf(fp, "f %d//1 %d//1 %d//1\n", 5 + r, 2 + r, 3 + r);
				fprintf(fp, "f %d//5 %d//5 %d//5\n", 6 + r, 3 + r, 4 + r);
				fprintf(fp, "f %d//9 %d//9 %d//9\n", 7 + r, 4 + r, 2 + r);
				fprintf(fp, "f %d//4 %d//4 %d//4\n", 5 + r, 9 + r, 8 + r);
				fprintf(fp, "f %d//8 %d//8 %d//8\n", 6 + r, 10 + r, 9 + r);
				fprintf(fp, "f %d//12 %d//12 %d//12\n", 7 + r, 8 + r, 10 + r);
				fprintf(fp, "f %d//2 %d//2 %d//2\n", 5 + r, 3 + r, 9 + r);
				fprintf(fp, "f %d//3 %d//3 %d//3\n", 5 + r, 8 + r, 2 + r);
				fprintf(fp, "f %d//7 %d//7 %d//7\n", 6 + r, 9 + r, 3 + r);
				fprintf(fp, "f %d//6 %d//6 %d//6\n", 6 + r, 4 + r, 10 + r);
				fprintf(fp, "f %d//11 %d//11 %d//11\n", 7 + r, 10 + r, 4 + r);
				fprintf(fp, "f %d//10 %d//10 %d//10\n", 7 + r, 2 + r, 8 + r);
				fprintf(fp, "f %d//4 %d//4 %d//4\n", 11 + r, 8 + r, 9 + r);
				fprintf(fp, "f %d//8 %d//8 %d//8\n", 11 + r, 9 + r, 10 + r);
				fprintf(fp, "f %d//12 %d//12 %d//12\n", 11 + r, 10 + r, 8 + r);

				r += 11;
			}
		}
	}

	for (l = 0; l < l0-1; l++) //cell2，转了60°，x坐标+0.5*x,y坐标+0.5*0.333*sqrt(3)*a,z坐标+0.5*z
	{
		for (n = 0; n < n0-1; n++)
		{
			for (m = 0; m < m0-1; m++)
			{

				point O1 = { 0.5*a + m * x + n * 0.5*x + 0.5*x,   0.5*0.333*sqrt(3)*a + n * y + 0.5*0.333*sqrt(3)*a,   0.00 + l * z + 0.5*z };

				point D2 = { 0.00 + m * x + n * 0.5*x + 0.5*x,    a*0.33*sqrt(3) + n * y + 0.5*0.333*sqrt(3)*a,        0.25*h + l * z + 0.5*z };
				point E3 = { 0.5*a + m * x + n * 0.5*x + 0.5*x,   -0.5*0.333*sqrt(3)*a + n * y + 0.5*0.333*sqrt(3)*a,  0.25*h + l * z + 0.5*z };
				point F4 = { a + m * x + n * 0.5*x + 0.5*x,       a*0.33*sqrt(3) + n * y + 0.5*0.333*sqrt(3)*a,        0.25*h + l * z + 0.5*z };

				point G5 = { 0.00 + m * x + n * 0.5*x + 0.5*x,    0.00 + n * y + 0.5*0.333*sqrt(3)*a,                  0.5*h + l * z + 0.5*z };
				point H6 = { a + m * x + n * 0.5*x + 0.5*x,       0.00 + n * y + 0.5*0.333*sqrt(3)*a,                  0.5*h + l * z + 0.5*z };
				point I7 = { 0.5*a + m * x + n * 0.5*x + 0.5*x,   0.5*sqrt(3)*a + n * y + 0.5*0.333*sqrt(3)*a,         0.5*h + l * z + 0.5*z };

				point D8 = { 0.00 + m * x + n * 0.5*x + 0.5*x,    a*0.33*sqrt(3) + n * y + 0.5*0.333*sqrt(3)*a,        0.75*h + l * z + 0.5*z };
				point E9 = { 0.5*a + m * x + n * 0.5*x + 0.5*x,   -0.5*0.333*sqrt(3)*a + n * y + 0.5*0.333*sqrt(3)*a,  0.75*h + l * z + 0.5*z };
				point F10 = { a + m * x + n * 0.5*x + 0.5*x,       a*0.33*sqrt(3) + n * y + 0.5*0.333*sqrt(3)*a,       0.75*h + l * z + 0.5*z };

				point O11 = { 0.5*a + m * x + n * 0.5*x + 0.5*x,  0.5*0.333*sqrt(3)*a + n * y + 0.5*0.333*sqrt(3)*a,   h + l * z + 0.5*z };

				fprintf(fp, "v %f %f %f\n", O1.x, O1.y, O1.z);
				fprintf(fp, "v %f %f %f\n", D2.x, D2.y, D2.z);
				fprintf(fp, "v %f %f %f\n", E3.x, E3.y, E3.z);
				fprintf(fp, "v %f %f %f\n", F4.x, F4.y, F4.z);
				fprintf(fp, "v %f %f %f\n", G5.x, G5.y, G5.z);
				fprintf(fp, "v %f %f %f\n", H6.x, H6.y, H6.z);
				fprintf(fp, "v %f %f %f\n", I7.x, I7.y, I7.z);
				fprintf(fp, "v %f %f %f\n", D8.x, D8.y, D8.z);
				fprintf(fp, "v %f %f %f\n", E9.x, E9.y, E9.z);
				fprintf(fp, "v %f %f %f\n", F10.x, F10.y, F10.z);
				fprintf(fp, "v %f %f %f\n", O11.x, O11.y, O11.z);

				fprintf(fp, "f %d//13 %d//13 %d//13\n", 1 + r, 3 + r, 2 + r);
				fprintf(fp, "f %d//15 %d//15 %d//15\n", 1 + r, 2 + r, 4 + r);
				fprintf(fp, "f %d//14 %d//14 %d//14\n", 1 + r, 4 + r, 3 + r);
				fprintf(fp, "f %d//13 %d//13 %d//13\n", 5 + r, 2 + r, 3 + r);
				fprintf(fp, "f %d//14 %d//14 %d//14\n", 6 + r, 3 + r, 4 + r);
				fprintf(fp, "f %d//15 %d//15 %d//15\n", 7 + r, 4 + r, 2 + r);
				fprintf(fp, "f %d//16 %d//16 %d//16\n", 5 + r, 9 + r, 8 + r);
				fprintf(fp, "f %d//17 %d//17 %d//17\n", 6 + r, 10 + r, 9 + r);
				fprintf(fp, "f %d//18 %d//18 %d//18\n", 7 + r, 8 + r, 10 + r);
				fprintf(fp, "f %d//7 %d//7 %d//7\n", 5 + r, 3 + r, 9 + r);
				fprintf(fp, "f %d//2 %d//2 %d//2\n", 5 + r, 8 + r, 2 + r);
				fprintf(fp, "f %d//6 %d//6 %d//6\n", 6 + r, 9 + r, 3 + r);
				fprintf(fp, "f %d//11 %d//11 %d//11\n", 6 + r, 4 + r, 10 + r);
				fprintf(fp, "f %d//10 %d//10 %d//10\n", 7 + r, 10 + r, 4 + r);
				fprintf(fp, "f %d//3 %d//3 %d//3\n", 7 + r, 2 + r, 8 + r);
				fprintf(fp, "f %d//16 %d//16 %d//16\n", 11 + r, 8 + r, 9 + r);
				fprintf(fp, "f %d//17 %d//17 %d//17\n", 11 + r, 9 + r, 10 + r);
				fprintf(fp, "f %d//18 %d//18 %d//18\n", 11 + r, 10 + r, 8 + r);

				r += 11;
			}
		}
	}


	fprintf(fp, "v %f %f %f\n", -thickness,               -thickness-0.5*a*0.33*sqrt(3),   l0*z+thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x , -thickness - 0.5*a*0.33*sqrt(3), l0*z + thickness);
	fprintf(fp, "v %f %f %f\n", -thickness,               y*n0 + thickness,                l0*z + thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x , y*n0 + thickness,                l0*z + thickness);

	fprintf(fp, "v %f %f %f\n", -thickness,               y*n0 + thickness,                -thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x , y*n0 + thickness,                -thickness);
	fprintf(fp, "v %f %f %f\n", -thickness,               -thickness - 0.5*a*0.33*sqrt(3), -thickness);
	fprintf(fp, "v %f %f %f\n", (n0 - 1)*0.5*x + m0 * x , -thickness - 0.5*a*0.33*sqrt(3), -thickness);

	fprintf(fp, "vn 0.0 0.0 1.0\n");
	fprintf(fp, "vn 0.0 1.0 0.0\n");
	fprintf(fp, "vn 0.0 0.0 -1.0\n");
	fprintf(fp, "vn 0.0 -1.0 0.0\n");
	fprintf(fp, "vn 1.0 0.0 0.0\n");
	fprintf(fp, "vn -1.0 0.0 0.0\n");
	//向量加18
	fprintf(fp, "f %d//19 %d//19 %d//19\n",1 + r,2 + r,3 + r);
	fprintf(fp, "f %d//19 %d//19 %d//19\n",3 + r,2 + r,4 + r);

	fprintf(fp, "f %d//20 %d//20 %d//20\n",3 + r,4 + r,5 + r);
	fprintf(fp, "f %d//20 %d//20 %d//20\n",5 + r,4 + r,6 + r);

	fprintf(fp, "f %d//21 %d//21 %d//21\n",5 + r,6 + r,7 + r);
	fprintf(fp, "f %d//21 %d//21 %d//21\n",7 + r,6 + r,8 + r);

	fprintf(fp, "f %d//22 %d//22 %d//22\n",7 + r,8 + r,1 + r);
	fprintf(fp, "f %d//22 %d//22 %d//22\n",1 + r,8 + r,2 + r);

	fprintf(fp, "f %d//23 %d//23 %d//23\n",2 + r,8 + r,4 + r);
	fprintf(fp, "f %d//23 %d//23 %d//23\n",4 + r,8 + r,6 + r);

	fprintf(fp, "f %d//24 %d//24 %d//24\n",7 + r,1 + r,5 + r);
	fprintf(fp, "f %d//24 %d//24 %d//24\n",5 + r,1 + r,3 + r);

	fclose(fp);

}