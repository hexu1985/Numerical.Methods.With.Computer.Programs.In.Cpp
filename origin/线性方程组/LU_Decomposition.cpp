//具有列选主元和从前到后代入的LU分解
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class lu
{
private:
	int i, j, k, n, *pivrow;
	double eps, pivot, sum, a1, a2, *b, **a;

public:
	void lu_input();
	void lu_decomposition();
	void lu_output();
	~lu()
	{
		delete[] b;
		delete[] pivrow;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	lu solution;
	solution.lu_input();
	solution.lu_decomposition();
	solution.lu_output();
}

void lu::lu_input()
{
	cout << "\n输入方程个数：";
	cin >> n;
	b = new double[n];
	pivrow = new int[n];
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
	cout << "\n输入最小主元素：";
	cin >> eps;
}

void lu::lu_decomposition()
{
//LU分解
	for (j = 0; j < n; j++)
	{
//计算上三角矩阵U
		if (j > 0)
		{
			for (i = 0; i < j; i++)
			{
				if (i > 0)
				{
					sum = 0.0;
					for (k = 0; k <= (i-1); k++)
					{
						sum += a[i][k]*a[k][j];
					}
				}
				else
				{
					sum = 0.0;
				}
				a[i][j] = a[i][j] - sum;
			}
		}
		pivot = 0.0;
//计算下三角矩阵L
		for (i = j; i < n; i++)
		{
			if (j > 0)
			{
				sum = 0.0;
				for (k = 0; k <= (j-1); k++)
				{
					sum += a[i][k] * a[k][j];
				}
			}
			else
			{
				sum = 0.0;
			}
			a[i][j] = a[i][j] - sum;
			if (fabs(a[i][j]) > pivot)
			{
				pivrow[j] = i;
				pivot = fabs(a[i][j]);
			}
		}
		if (pivot < eps)
		{
			cout << "\n矩阵可能奇异，失败..." << endl;
			exit(0);
		}
//列选主元
		if (pivrow[j] != j)
		{
			for (k = 0; k < n; k++)
			{
				a1 = a[pivrow[j]][k];
				a[pivrow[j]][k] = a[j][k];
				a[j][k] = a1;
			}
		}
//计算下三角矩阵L
		if (j != (n-1))
		{
			for (i = (j+1); i < n; i++)
			{
				a[i][j] /= a[j][j];
			}
		}
	}
//从前到后代入，先计算LY = B
	for (i = 0; i < n; i++)
	{
		sum = b[pivrow[i]];
		b[pivrow[i]] = b[i];
		if (i > 0)
		{
			for (j = 0; j < (i-1); j++)
			{
				sum -= a[i][j]*b[j];
			}
		}
		b[i] = sum;
	}
//再计算UX = Y
	for (i = (n-1); i >= 0; i--)
	{
		sum = b[i];
		if (i < (n-1))
		{
			for (j = (i+1); j < n; j++)
			{
				sum -= a[i][j]*b[j];
			}
		}
		b[i] = sum / a[i][i];
	}
}

void lu::lu_output()
{
	cout << "\n结果是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << b[i] << endl;
	}
}