//用具有最大主元素的Gauss-Jordan消去法求矩阵的逆
#include <iostream>
#include <math.h>
#include <fstream>
#include <process.h>

using namespace std;

class inverse
{
private:
	int i, j, k, n, flag, scani, scanj, *row, *col;
	double eps, sum, pivot, aijcolk, *y, **a, **b, **c;

public:
	void inverse_input();
	void inverse_jordan_reduction();
	void inverse_output();
	void inverse_check();
	~inverse()
	{
		delete[] row, col, y;
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
	inverse inversion;
	inversion.inverse_input();
	inversion.inverse_jordan_reduction();
	inversion.inverse_output();
	inversion.inverse_check();
}

void inverse::inverse_input()
{
	ifstream fin("inverse.txt");
	fin >> n;
	n = 3;
	row = new int[n];
	col = new int[n];
	y = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	b = new double*[n];
	for (i = 0; i < n; i++)
	{
		b[i] = new double[n];
	}
	c = new double*[n];
	for (i = 0; i < n; i++)
	{
		c[i] = new double[n];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fin >> a[i][j];
			b[i][j] = a[i][j];
		}
	fin >> eps;
	fin.close();
}

void inverse::inverse_jordan_reduction()
{
	for (k = 0; k < n; k++)
	{
		pivot = 0.0;
		for (i = 0; i < n; i++)
		{
			flag = 0;
			for (j = 0; j < n; j++)
			{
				flag = 0;
				if (k > 0)
				{
					for (scani = 0; scani <= (k-1); scani++)
						for (scanj = 0; scanj <= (k-1); scanj++)
						{
							if ((i == row[scani]) || (j == col[scanj]))
							{
								flag = 1;
							}
						}
				}
				else
				{
					flag = 0;
				}
				if (flag == 0)
				{
					if (fabs(a[i][j]) > fabs(pivot))
					{
						pivot = a[i][j];
						row[k] = i;
						col[k] = j;
					}
				}
			}
		}
		if (fabs(pivot) > eps)
		{
			for (j = 0; j < n; j++)
			{
				if (j == col[k])
				{
					a[row[k]][col[k]] = 1.0 / pivot;
				}
				else
				{
					a[row[k]][j] /= pivot;
				}
			}
			for (i = 0; i < n; i++)
			{
				aijcolk = a[i][col[k]];
				if (i != row[k])
				{
					for (j = 0; j < n; j++)
					{
						if (j == col[k])
						{
							a[i][col[k]] /= -pivot;
						}
						else
						{
							a[i][j] -= aijcolk * a[row[k]][j];
						}
					}
				}
			}
		}
		else
		{
			cout << "\n最大的主元素 = " << pivot << endl;
			cout << "\n矩阵可能奇异，失败..." << endl;
			exit(0);
		}
	}
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			y[col[i]] = a[row[i]][j];
		}
		for (i = 0; i < n; i++)
		{
			a[i][j] = y[i];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			y[row[j]] = a[i][col[j]];
		}
		for (j = 0; j < n; j++)
		{
			a[i][j] = y[j];
		}
	}
}

void inverse::inverse_output()
{
	ofstream fout("inverse.out");
	fout << "\n逆矩阵是：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fout << "\na[" << i << "][" << j << "] = " << a[i][j] << endl;
		}
	fout.close();
}

void inverse::inverse_check()
{
	ofstream fout("inverse_check.out");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			sum = 0.0;
			for (k = 0; k < n; k++)
			{
				sum += b[i][k]*a[k][j];
			}
			c[i][j] = sum;
		}
	fout << endl << "\n输入的矩阵与它的逆矩阵的乘积：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fout << "\nc[" << i << "][" << j << "] = " << c[i][j] << endl;
		}
	fout.close();
}