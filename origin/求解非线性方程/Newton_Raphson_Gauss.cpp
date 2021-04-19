//用Newton_Raphson法求解非线性方程组
#include <iostream>
#include <math.h>
#include <process.h>
#include <stdlib.h>

using namespace std;

class multivariable
{
private:
	int epsilon, i, iteration, j, k, n, *pivrow, **pivcol;
	double df0_0, df0_1, df0_2, df1_0, df1_1, df1_2, df2_0, df2_1, df2_2;
	double al, aik, eps, error, pivot, sum, x0, x1, x2;
	double *s, *z, *F, *x_new, *x_old, **a;

public:
	multivariable()
	{
		iteration = 0;
		epsilon = 1;
	}
	void memory_allocation();
	void functions();
	void matrix_elements();
	void gauss();
	double sorting(double *);
	void solution();
	~multivariable()
	{
		delete[] pivrow;
		for (i = 0; i < n; i++)
		{
			delete[] pivcol[i];
		}
		delete[] pivcol;
		delete[] s, z, F, x_new, x_old;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	multivariable newton;
	newton.solution();
}

void multivariable::memory_allocation()
{
	pivrow = new int[n];
	pivcol = new int*[n];
	for (i = 0; i < n; i++)
	{
		pivcol[i] = new int[2];
	}
	s = new double[n];
	z = new double[n];
	F = new double[n];
	x_new = new double[n];
	x_old = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n+1];
	}
}

void multivariable::functions()
{
	x0 = x_old[0];
	x1 = x_old[1];
	x2 = x_old[2];
	F[0] = pow((1 - sin(x0)), 2) + pow((1.5 - sin(x1)), 2) + pow((cos(x0) - cos(x1)), 2) - pow((x2 + 0.25), 2);
	F[1] = (x2 + 0.25) * sin(x0) + 2 * x2 * (cos(x1) * sin(x0) - cos(x0));
	F[2] = (x2 + 0.25) * sin(x1) + 2 * x2 * (sin(x1) * cos(x0) - 1.5 * cos(x1));
	df0_0 = 2 * cos(x0) * (sin(x0) - 1) + 2 * sin(x0) * (cos(x1) - cos(x0));
	df0_1 = 2 * cos(x1) * (sin(x1) - 1.5) + 2 * sin(x1) * (cos(x0) - cos(x1));
	df0_2 = -2 * (x2 + 0.25);
	df1_0 = cos(x0) * (x2 + 0.25) + 2 * x2 * (cos(x1) * cos(x0) + sin(x0));
	df1_1 = -2 * x2 * sin(x0) * sin(x1);
	df1_2 = sin(x0) + 2 * (cos(x1) * sin(x0) - cos(x0));
	df2_0 = -2 * x2 * sin(x0) * sin(x1);
	df2_1 = (x2 + 0.25) * cos(x1) + 2 * x2 * (cos(x0) * cos(x1) + 1.5 * sin(x1));
	df2_2 = sin(x1) + 2 * (sin(x1) * cos(x0) - 1.5 * cos(x1));
}

void multivariable::matrix_elements()
{
	a[0][0] = df0_0;
	a[0][1] = df0_1;
	a[0][2] = df0_2;
	a[1][0] = df1_0;
	a[1][1] = df1_1;
	a[1][2] = df1_2;
	a[2][0] = df2_0;
	a[2][1] = df2_1;
	a[2][2] = df2_2;
}

void multivariable::gauss()
{
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
		if (pivot < 1e-10)
		{
			cout << "\n矩阵可能奇异，失败..." << endl;
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
	x_new[n-1] = a[n-1][n] / a[n-1][n-1];
	for (i = (n - 2); i >= 0; i--)
	{
		sum = 0.0;
		for (j = (i + 1); j < n; j++)
		{
			sum += a[i][j] * x_new[j];
		}
		x_new[i] = (a[i][n] - sum) / a[i][i];
	}
	for (k = (n - 2); k >= 0; k--)
	{
		al = x_new[pivcol[k][1]];
		x_new[pivcol[k][1]] = x_new[pivcol[k][0]];
		x_new[pivcol[k][0]] = al;
	}
}

double multivariable::sorting(double *y)
{
	int doublecmp(const void *, const void *);
	for (i = 0; i < n; i++)
	{
		s[i] = fabs(y[i]);
	}
	qsort(s, n, sizeof(double), doublecmp);
	return(s[n-1]);
}

int doublecmp(const void *v1, const void *v2)
{
	double p = ((*(double *)v1 - *(double *)v2));
	if (p < 0)
		return (-1);
	else if (p == 0)
		return (0);
	else
		return (1);
}

void multivariable::solution()
{
	n = 3;
	memory_allocation();
	cout << "\n输入所有未知数的初始估值：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入初值x[" << i << "] = ";
		cin >> x_old[i];
	}
	cout << "\n输入公差：";
	cin >> eps;
	do
	{
		iteration++;
		functions();
		matrix_elements();
		for (i = 0; i < n; i++)
		{
			a[i][n] = -F[i];
		}
		gauss();
		for (i = 0; i < n; i++)
		{
			z[i] = x_new[i];
			x_new[i] = z[i] + x_old[i];
		}
		error = sorting(z) / sorting(x_new);
		if (error < eps)
		{
			epsilon = 0;
		}
		if (epsilon == 1)
		{
			for (i = 0; i < n ; i++)
			{
				x_old[i] = x_new[i];
			}
		}
	}while (epsilon == 1);
	cout << "\n解是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx_new[" << i << "] = " << x_new[i] << endl;
	}
	cout << "\n收敛于" << iteration << "次迭代" << endl;
}