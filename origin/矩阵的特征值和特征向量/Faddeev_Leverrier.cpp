//Faddeev_Leverrier法确定矩阵特征方程系数
#include <iostream>

using namespace std;

class faddeev
{
private:
	int i, j, k, l, n;
	double sum1, sum2;
	double *alpha;
	double **a, **b, **c;

public:
	void solution();
	double trace();
	~faddeev()
	{
		delete[] alpha;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
		for (i = 0; i < n; i++)
		{
			delete[] b[i];
		}
		delete[] b;
		for (i = 0; i < n; i++)
		{
			delete[] c[i];
		}
		delete[] c;
	}
};

void main()
{
	faddeev eigen;
	eigen.solution();
}

//Faddeev_Leverrier法
void faddeev::solution()
{
	cout << "输入矩阵阶数：";
	cin >> n;
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	b = new double*[n];
	for (i = 0; i < n; i++)
	{
		b[i] = new double[n];
	}
	c = new double*[n];
	for (i = 0; i < n; i++)
	{
		c[i] = new double[n];
	}
	alpha = new double[n+1];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	alpha[0] = 1.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			b[i][j] = a[i][j];
		}
	alpha[1] = trace();
	for (k = 2; k <= n; k++)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i == j)
				{
					c[i][j] = b[i][j] - alpha[k-1];
				}
				else
				{
					c[i][j] = b[i][j];
				}
			}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				sum2 = 0.0; 
				for (l = 0; l < n; l++)
				{
					sum2 += a[i][l]*c[l][j];
				}
				b[i][j] = sum2;
			}
		alpha[k] = trace() / k;
	}
	cout << "\n特征多项式的系数是：" << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "\nalpha[" << i << "] = " << alpha[i] << endl;
	}
}

//计算矩阵迹的函数
double faddeev::trace()
{
	sum1 = 0.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				sum1 += b[i][j];
			}
		}
	return(sum1);
}