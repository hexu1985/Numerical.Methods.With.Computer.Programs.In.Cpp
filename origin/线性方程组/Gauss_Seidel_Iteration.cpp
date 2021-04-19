//Gauss_Seidel迭代法求解对角线占绝对优势的系统
#include <iostream>
#include <math.h>

using namespace std;

class seidel
{
private:
	int i, j, n, flag, iteration;
	double xold, error, sum, eps;
	double *x, *b, **a;

public:
	seidel()
	{
		iteration = 0;
	}
	void seidel_input();
	void seidel_subst();
	void seidel_output();
	~seidel()
	{
		delete[] x, b;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	seidel solution;
	solution.seidel_input();
	solution.seidel_subst();
	solution.seidel_output();
}

void seidel::seidel_input()
{
	cout << "\n输入方程的个数：";
	cin >> n;
	x = new double[n];
	b = new double[n];
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
	for (i = 0; i < n; i++)
	{
		cout << "\n输入b[" << i << "] = ";
		cin >> b[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	cout << "\n输入相对误差容许量：";
	cin >> eps;
}

void seidel::seidel_subst()
{
	do
	{
		flag = 0;
		iteration++;
		for (i = 0; i < n; i++)
		{
			xold = x[i];
			sum = 0.0;
			for (j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += a[i][j]*x[j];
				}
			}
			x[i] = (b[i] - sum) / a[i][i];
			error = fabs(xold - x[i]) / x[i];
			if (error >= eps)
			{
				flag = 1;
			}
		}
	}while (flag == 1);
}

void seidel::seidel_output()
{
	cout << "\n结果是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i];
	}
	cout << "\n迭代次数 = " << iteration << endl;
}