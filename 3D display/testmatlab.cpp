#include"mex.h"
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
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
	mexPrintf("Hello!\n");
}