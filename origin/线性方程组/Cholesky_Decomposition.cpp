//Cholesky分解求解对称正定矩阵

#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class cholesky
{
private:
	int i, j, k, n;
	double sum, *b, *d, *x, **a;

public:
	void cholesky_input();
	void cholesky_decomposition();
	void cholesky_output();
	~cholesky()
	{
		delete[] b;
		delete[] d;
		delete[] x;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	cholesky solution;
	solution.cholesky_input();
	solution.cholesky_decomposition();
	solution.cholesky_output();
}

void cholesky::cholesky_input()
{
	cout << "\n输入方程个数：";
	cin >> n;
	b = new double[n];
	d = new double[n];
	x = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	for (i =0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] != a[j][i])
			{
				cout << "\n系数矩阵不对称，失败..." << endl;
				exit(0);
			}
		}
	for (i = 0; i < n; i++)
	{
		cout << "\n输入b[" << i << "] = ";
		cin >> b[i];
	}
}

void cholesky::cholesky_decomposition()
{
//cholesky分解
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			sum = a[i][j];
			for (k = 0; k <= (i-1); k++)
			{
				sum -= a[i][k]*a[j][k];
			}
			if (i == j)
			{
				if (sum <= 0)
				{
					cout << "\n矩阵非正定，失败..." << endl;
					exit(0);
				}
				d[i] = sqrt(sum);
			}
			else
			{
				a[j][i] = sum / d[i];
			}
		}
//前向代入
		for (i = 0; i < n; i++)
		{
			sum = b[i];
			for (k = 0; k <= (i-1); k++)
			{
				sum -= a[i][k]*x[k];
			}
			x[i] = sum / d[i];
		}
//后向代入
		for (i = (n-1); i >= 0; i--)
		{
			sum = x[i];
			for (k = (i+1); k < n; k++)
			{
				sum -= a[k][i]*x[k];
			}
			x[i] = sum / d[i];
		}
}

void cholesky::cholesky_output()
{
	cout << "\n结果是：" << endl;
	for (i= 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}