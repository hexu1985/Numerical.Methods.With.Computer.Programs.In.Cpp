//Householder变换将对称矩阵化为三对角形式
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

class householder
{
private:
	int i, j, k, m, n, sgn;
	double eps, s, sum;
	double *w;
	double **a, **b, **c;

public:
	householder()
	{
		eps = 1e-8;
	}
	void solution();
	double compute_s();
	int sign();
	~householder()
	{
		delete[] w;
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
	householder tridiagonal;
	tridiagonal.solution();
}

void householder::solution()
{
	cout << "输入矩阵阶数：";
	cin >> n;
	w = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	b =  new double*[n];
	for (i = 0; i < n; i++)
	{
		b[i] = new double[n];
	}
	c =  new double*[n];
	for (i = 0; i < n; i++)
	{
		c[i] = new double[n];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	for (k = 0; k < (n-2); k++)
	{
		s = compute_s();
		if (s > eps)
		{
			for (i = 0; i < n; i++)
			{
				w[i] = 0.0;
			}
			w[k+1] = sqrt(0.5 * (1 + fabs(a[k][k+1]) / s));
			for (i = (k+2); i < n; i++)
			{
				w[i] = (a[k][i] / (2 * s * w[k+1])) * sign();
			}
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					c[i][j] = w[i] * w[j];
				}
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i == j)
					{
						b[i][j] = 1.0;
					}
					else
					{
						b[i][j] = 0.0;
					}
				}
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					b[i][j] -= 2 * c[i][j];
				}
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					c[i][j] = 0.0;
					for (m = 0; m < n; m++)
					{
						c[i][j] += a[i][m] * b[m][j];
					}
				}
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					a[i][j] = 0.0;
					for (m = 0; m < n; m++)
					{
						a[i][j] += b[i][m] * c[m][j];
					}
				}
		}
	}
	cout << "\n三对角矩阵是：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\na[" << i << "][" << j << "] = " << a[i][j] << endl;
			getchar();
		}
}

double householder::compute_s()
{
	sum = 0.0;
	for (i = (k+1); i < n; i++)
	{
		sum += a[k][i] * a[k][i];
	}
	sum = sqrt(sum);
	return(sum);
}

int householder::sign()
{
	if (fabs(a[k][k+1]) < eps)
	{
		sgn = 1;
	}
	else if (a[k][k+1] < 0)
	{
		sgn = -1;
	}
	else
	{
		sgn = 1;
	}
	return(sgn);
}