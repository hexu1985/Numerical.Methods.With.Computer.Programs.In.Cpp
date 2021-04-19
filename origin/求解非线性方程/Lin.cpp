//用Lin法求解多方式方程共轭复根
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class lin
{
private:
	int flag, iteration, iteration_max, k, n;
	double eps, gamma, delta, r1, r2, *a, *b;

public:
	lin()
	{
		iteration = 0;
		flag = 0;
		iteration_max = 1000;
		eps = 1.0e-5;
	}
	void solution();
	~lin()
	{
		delete[] a, b;
	}
};

void main()
{
	lin roots;
	roots.solution();
}

void lin::solution()
{
	cout << "\n输入多项式阶数：";
	cin >> n;
	if (n < 4)
	{
		cout << "\n至少4阶。" << endl;
		exit(0);
	}
	a = new double[n+1];
	b = new double[n-1];
	for (k = 0; k <= n; k++)
	{
		cout << "\n输入a[" << k << "] = ";
		cin >> a[k];
	}
	for (k = 1; k <= n; k++)
	{
		a[k] /= a[0];
	}
	a[0] = 1.0;
	b[0] = 1.0;
	cout << "\n输入gamma和delta的初值：";
	cin >> gamma >> delta;
	do
	{
		iteration++;
		for (k = 1; k <= (n - 2); k++)
		{
			if (k == 1)
			{
				b[k] = a[k] - gamma;
			}
			else
			{
				b[k] = a[k] - gamma * b[k-1] - delta * b[k-2];
			}
			r1 = a[n-1] - gamma * b[n-2] - delta * b[n-3];
			r2 = a[n] - delta * b[n-2];
			if ((fabs(r1) < eps) && (fabs(r2) < eps))
			{
				flag = 1;
			}
			if (flag != 1)
			{
				delta = a[n] / b[n-2];
				gamma = (a[n-1] - delta * b[n-3]) / b[n-2];
			}
			if (iteration > iteration_max)
			{
				cout << "\n在" << iteration_max << "次迭代后不收敛" << endl;
				cout << gamma << "     " << delta << endl;
				for (k = 0; k <= (n-2); k++)
				{
					cout << "\nb[" << k << "] = " << b[k] << endl;
				}
				exit(0);
			}
		}
	}while (flag == 0);
	cout << "\n迭代次数 = " << iteration << endl;
	cout << "\ngamma = " << gamma << endl;
	cout << "\ndelta = " << delta << endl;
	for (k = 0; k <= (n - 2); k++)
	{
		cout << "\nb[" << k << "] = " << b[k] << endl;
	}
}