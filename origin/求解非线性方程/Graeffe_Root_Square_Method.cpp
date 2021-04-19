//用Graeffe法求解多项式方程单实根
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class graeffe
{
private:
	int flag, i, iteration, iteration_max, k, n;
	double eps, pp, pm, root, sum, upper_limit, lower_limit, val, *a, *b, *c;

public:
	graeffe()
	{
		iteration = 0;
		flag = 0;
		iteration_max = 100;
		upper_limit = 1e35;
		lower_limit = 1e-35;
	}
	void solution();
	~graeffe()
	{
		delete[] a, b, c;
	}
};

void main()
{
	graeffe roots;
	roots.solution();
}

void graeffe::solution()
{
	cout << "\n输入多项式阶数：";
	cin >> n;
	a = new double[n+1];
	b = new double[n+1];
	c = new double[n+1];
	for (i = 0; i <= n; i++)
	{
		cout << "\n输入a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "\n输入可以认为多项式值为0的量：";
	cin >> eps;
	for (i = 1; i <= n; i++)
	{
		a[i] /= a[0];
		c[i] = a[i];
	}
	a[0] = 1.0;
	b[0] = 1.0;
	c[0] = 1.0;
	do
	{
		iteration++;
		for (i = 1; i <= n; i++)
		{
			sum = 0.0;
			for (k = 1; k <= i; k++)
			{
				if ((i + k) <= n)
				{
					sum += pow((-1.0), k) * c[i+k] * c[i-k];
				}
			}
			b[i] = pow((-1.0), i) * (c[i] * c[i] + 2 * sum);
		}
		for (i = 0; i <= n; i++)
		{
			if (b[i] != 0)
			{
				if ((fabs(b[i]) > upper_limit) || (fabs(b[i]) < lower_limit))
				{
					flag = 1;
				}
			}
		}
		if (flag != 1)
		{
			for (i = 1; i <= n; i++)
			{
				c[i] = b[i];
			}
		}
		if (iteration > iteration_max)
		{
			cout << "\n经过" << iteration_max << "次迭代没有找到根。";
			exit(0);
		}
	}while (flag == 0);
	cout << "\n迭代次数 = " << iteration << endl;
	for (i = 1; i <= n; i++)
	{
		if (b[i] == 0)
		{
			cout << "\n错误，A[" << i << "] = 0" << endl;
			exit(0);
		}
	}
	for (i = 1; i <= n; i++)
	{
		root = pow(fabs(b[i] / b[i-1]), pow(2.0, (-iteration)));
		pp = 1.0;
		pm = 1.0;
		for (k = 1; k <= n; k++)
		{
			pp = pp * root + a[k];
			pm = pm * (-root) + a[k];
		}
		if (fabs(pp) > fabs(pm))
		{
			root = -root;
			val = pm;
		}
		else
		{
			val = pp;
		}
		if (fabs(val) < eps)
		{
			cout << "\n找到了根，根 = " << root << endl;
		}
		else
		{
			cout << "\n可能没有根，根的值 = " << root << "。多项式的值 = " << val << endl;
		}
	}
}