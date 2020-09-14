#include"mex.h"
void triangle(int i)  //第i层，从1开始，由i和w一起决定点A、B、C的位置  1层
{
	i = i + 15;
	float a = 10.0f;// 三角形边长 这里来控制缩放

	float width = 0.4; //喷头的宽度,或者变化的速率，现在看来就是每次偏移的距离，和真实碰头宽度配合决定了角度，即变化率

	int m = 0;  //行
	int n = 0;  //列
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
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段一：w*i 在 0——sqrt(3)/3 *a
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
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)   //阶段二：w*i在 sqrt(3)/3 *a——2 * sqrt(3)/3 *a
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
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段三：和阶段一的区别只是Y坐标全变成负
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
		for (m; m < (120 * 2) / (sqrt(3)*a); m++)  //阶段四：和阶段二一样
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

	default: printf("有问题");
		break;
	}

}
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	mexPrintf("Hello!\n");
}