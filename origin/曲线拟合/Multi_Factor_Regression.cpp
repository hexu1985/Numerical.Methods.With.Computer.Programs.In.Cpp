//多元回归
#include <iostream>
#include <math.h>
#include <fstream>
#include <process.h>

using namespace std;

class multiple
{
private:
	int i, j, k, m, n;
	int *pivrow, **pivcol;
	double alpha, sum1, sum2, sum3, sum4, sum5, sum6, sum7, term1, term2, term3, term4;
	double pivot, rsq, sum, rsq_num, rsq_denom, aik, al;
	double *b, *y, *y_model, **a, **x;

public:
	multiple()
	{
		rsq_num = 0.0;
		rsq_denom = 0.0;
	}
	void input();
	void mult_regression();
	void r_sq();
	~multiple()
	{
		delete[] y, y_model;
		delete[] b, pivrow;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
		for (i = 0; i < n; i++)
		{
			delete[] pivcol[i];
		}
		delete[] pivcol;
		for (i = 0; i < n; i++)
		{
			delete[] x[i];
		}
		delete[] x;
	}
};

void main()
{
	multiple multi;
	multi.input();
	multi.mult_regression();
}

void multiple::input()
{
	ifstream fin("multi.txt");
	fin >> m;
	fin >> n;
	if (n > (m - 1))
	{
		cout << "\n数据不够，终止..." << endl;
		exit(0);
	}
	y = new double[m];
	y_model = new double[m];
	b = new double[n];
	pivrow = new int[n];
	pivcol = new int*[n];
	for (i = 0; i < n; i++)
	{
		pivcol[i] = new int[2];
	}
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n+1];
	}
	x = new double*[n];
	for (i = 0; i < n; i++)
	{
		x[i] = new double[m];
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			fin >> x[j][i];
		}
		fin >> y[i];
	}
	fin.close();
}

//多元回归函数
void multiple::mult_regression()
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum1 = 0.0;
			sum2 = 0.0;
			sum3 = 0.0;
			sum4 = 0.0;
			sum5 = 0.0;
			for (k = 0; k < m; k++)
			{
				sum1 += x[i][k] * x[j][k];
				sum2 += x[i][k];
				sum3 += x[j][k];
				sum4 += x[i][k] * y[k];
				sum5 += y[k];
			}
			term1 = sum1;
			term2 = sum2 * sum3 / m;
			term3 = sum4;
			term4 = sum2 * sum5 / m;
			a[i][j] = term1 - term2;
		}
		a[i][n] = term3 - term4;
	}
	//全主元Guass消去法
	for (k = 0; k < (n-1); k++)
	{
		pivot = fabs(a[k][k]);
		pivrow[k] = k;
		pivcol[k][0] = k;
		pivcol[k][1] = k;
		for (i = k; i < n; i++)
			for (j = k; j < n; j++)
			{
				if (pivot < fabs(a[i][j]))
				{
					pivot = fabs(a[i][j]);
					pivrow[k] = i;
					pivcol[k][1] = j;
				}
			}
		if (pivot < 1.0e-10)
		{
			cout << "\n矩阵奇异，异常中断..." << endl;
			exit(0);
		}
		if (pivrow[k] != k)
		{
			for (j = k; j < (n + 1); j++)
			{
				al = a[pivrow[k]][j];
				a[pivrow[k]][j] = a[k][j];
				a[k][j] = al;
			}
		}
		if (pivcol[k][1] != k)
		{
			for (i = 0; i < n; i++)
			{
				al = a[i][pivcol[k][1]];
				a[i][pivcol[k][1]] = a[i][k];
				a[i][k] = al;
			}
		}
		if (k != (n - 1))
		{
			for (i = k + 1; i < n; i++)
			{
				aik = a[i][k];
				for (j = k; j < (n + 1); j++)
				{
					a[i][j] -= aik * a[k][j] / a[k][k];
				}
			}
		}
	}
	//回代
	b[n-1] = a[n-1][n] / a[n-1][n-1];
	for (i = (n - 2); i >= 0; i--)
	{
		sum = 0.0;
		for (j = (i + 1); j < n; j++)
		{
			sum += a[i][j] * b[j];
		}
		b[i] = (a[i][n] - sum) / a[i][i];
	}
	for (k = (n - 2); k >= 0; k--)
	{
		al = b[pivcol[k][1]];
		b[pivcol[k][1]] = b[pivcol[k][0]];
		b[pivcol[k][0]] = al;
	}
	sum6 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum2 = 0.0;
		for (k = 0; k < m; k++)
		{
			sum2 += x[i][k];
		}
		sum6 += b[i] * sum2;
	}
	alpha = (sum5 - sum6) / m;
	cout << "\n拟合多元回归：y = a + b0 * x0 + b1 * x1 + ..." << endl;
	cout << "\n自变量个数（n） = " << n << endl;
	cout << "\n系数是：" << endl;
	cout << "\na = " << alpha << endl;
	for (i = 0; i < n; i++)
	{
		cout << endl << "b" << i << " = " << b[i] << endl;
	}
	for (i = 0; i < m; i++)
	{
		sum7 = 0.0;
		for (j = 0; j < n; j++)
		{
			sum7 += b[j] * x[j][i];
		}
		y_model[i] = alpha + sum7;
	}
	r_sq();
}

void multiple::r_sq()
{
	for (i = 0; i < m; i++)
	{
		rsq_num += pow((y_model[i] - sum5 / m), 2);
		rsq_denom += pow((y[i] - sum5 / m), 2);
	}
	rsq = rsq_num / rsq_denom;
	cout << "\n r^2 = " << rsq << endl;
}