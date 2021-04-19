//超松弛Gauss_Seidel迭代
#include <iostream>
#include <math.h>

using namespace std;

class relaxation
{
private:
	int i, j, n, flag, iteration;
	double error, sum, eps, w;
	double *x, *xold, *b, **a;

public:
	relaxation()
	{
		iteration = 0;
	}
	void relaxation_input();
	void relaxation_subst();
	void relaxation_output();
	~relaxation()
	{
		delete[] x, xold, b;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	relaxation solution;
	solution.relaxation_input();
	solution.relaxation_subst();
	solution.relaxation_output();
}

void relaxation::relaxation_input()
{
	cout << "\n输入方程的个数：";
	cin >> n;
	x = new double[n];
	xold = new double[n];
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
	cout << "\n输入权因子w = ";
	cin >> w;
	cout << "\n输入相对误差容许量：";
	cin >> eps;
}

void relaxation::relaxation_subst()
{
	do
	{
		flag = 0;
		iteration++;
		for (i = 0; i < n; i++)
		{
			xold[i] = x[i];
			sum = 0.0;
			for (j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += a[i][j]*x[j];
				}
			}
			x[i] = (b[i] - sum) / a[i][i];
		}
		for (i = 0; i < n; i++)
		{
			x[i] = w*x[i] + (1-w)*xold[i];
		}
		for (i = 0; i < n; i++)
		{
			error = fabs((xold[i] - x[i]) / x[i]);
			if (error >= eps)
			{
				flag = 1;
			}
		}
	}while (flag == 1);
}

void relaxation::relaxation_output()
{
	cout << "\n结果是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i];
	}
	cout << "\n收敛于" << iteration << "次迭代" << endl;
}