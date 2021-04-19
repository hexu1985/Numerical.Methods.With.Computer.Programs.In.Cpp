//曲线回归最小二乘多项式
#include <iostream>
#include <math.h>
#include <fstream>
#include <process.h>

using namespace std;

class polynomial
{
private:
	int i, j, k, m, n;
	int *pivrow, **pivcol;
	double alpha, sum1, sum2, sum3, sum4, sum5, sum6, sum7, term1, term2, term3, term4;
	double pivot, rsq, sum, rsq_num, rsq_denom, aik, al;
	double *b, *x, *y, *y_model, **a;

public:
	polynomial()
	{
		rsq_num = 0.0;
		rsq_denom = 0.0;
	}
	void input();
	void poly_line();
	void r_sq();
	~polynomial()
	{
		delete[] x, y, y_model;
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
	}
};

int main()
{
	polynomial poly;
	poly.input();
	poly.poly_line();
}

void polynomial::input()
{
	ifstream fin("poly.txt");
	fin >> m;
	cout << "\n输入多项式阶数（最大 = " << m - 1 << "）：";
	cin >> n;
	if (n > (m - 1))
	{
		cout << "\n错误的阶数，终止..." << endl;
		exit(0);
	}
	x = new double[m];
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
		a[i] = new double[n + 1];
	}
	for (i = 0; i < m; i++)
	{
		fin >> x[i] >> y[i];
	}
	fin.close();
}

//拟合多项式曲线的函数
void polynomial::poly_line()
{
	//计算系数b[i]
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			sum1 = 0.0;
			sum2 = 0.0;
			sum3 = 0.0;
			sum4 = 0.0;
			sum5 = 0.0;
			for (k = 0; k < m; k++)
			{
				sum1 += pow(x[k], (i + j));
				sum2 += pow(x[k], i);
				sum3 += pow(x[k], j);
				sum4 += pow(x[k], i) * y[k];
				sum5 += y[k];
			}
			term1 = sum1;
			term2 = sum2 * sum3 / m;
			term3 = sum4;
			term4 = sum2 * sum5 / m;
			a[i-1][j-1] = term1 - term2;
		}
		a[i-1][n] = term3 - term4;
	}
	//全主元Guass消去法
	for (k = 0; k < (n - 1); k++)
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
			for (i = (k + 1); i < n; i++)
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
	for (i = 1; i <= n; i++)
	{
		sum2 = 0.0;
		for (k = 0; k < m; k++)
		{
			sum2 += pow(x[k], i);
		}
		sum6 += b[i-1] * sum2;
	}
	alpha = (sum5 - sum6) / m;
	cout << "\n拟合多项式：Y = a + b0 * x + b1 * x^2 + ..." << endl;
	cout << "\n阶数（n） = " << n << endl;
	cout << "\n系数是：" << endl;
	cout << "\na = " << alpha << endl;
	for (i = 0; i < n; i++)
	{
		cout << endl << "b" << i << " = " << b[i] << endl;
	}
	for (i = 0; i < m; i++)
	{
		sum7 = b[n-1];
		for (j = (n-2); j >= 0; j--)
		{
			sum7 = sum7 * x[i] + b[j];
		}
		y_model[i] = sum7 * x[i] + alpha;
	}
	r_sq();
}

void polynomial::r_sq()
{
	for (i = 0; i < m; i++)
	{
		rsq_num += pow((y_model[i] - sum5 / m), 2);
		rsq_denom += pow((y[i] - sum5 / m), 2);
	}
	rsq = rsq_num / rsq_denom;
	cout << "\n r^2 = " << rsq << endl;
}