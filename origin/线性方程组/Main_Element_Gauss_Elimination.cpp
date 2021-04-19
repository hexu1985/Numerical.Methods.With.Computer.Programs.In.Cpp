//全选主元Gauss消去法
#include <iostream>
#include <fstream>
#include <math.h>
#include <process.h>

using namespace std;

class gauss
{
private:
	int i, j, k, n, *pivrow, **pivcol;
	double eps, pivot, sum, aik, al, *x, **a;

public:
	void gauss_input();
	void gauss_elimination();
	void gauss_output();
	~gauss()
	{
		delete[] x;
		delete[] pivrow;
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

void main()
{
	gauss solution;
	solution.gauss_input();
	solution.gauss_elimination();
	solution.gauss_output();
}

void gauss::gauss_input()
{
	ifstream fin("gauss.txt");
	fin >> n;
	x = new double[n];
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
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			fin >> a[i][j];
		}
	for(i = 0; i < n; i++)
	{
		fin >> a[i][n];
	}
	fin >> eps;
	fin.close();
}

void gauss::gauss_elimination()
{
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
		if (pivot < eps)
		{
			cout << "\n矩阵可能奇异，失败..." << endl;
			exit(0);
		}
		if (pivrow[k] != k)
		{
			for (j = k; j < (n+1); j++)
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
		if (k != (n-1))
		{
			for (i = (k+1); i < n; i++)
			{
				aik = a[i][k];
				for (j = k; j < (n+1); j++)
				{
					a[i][j] -= aik * a[k][j] / a[k][k];
				}
			}
		}
	}
	x[n-1] = a[n-1][n] / a[n-1][n-1];
	for (i = (n-2); i >= 0; i--)
	{
		sum = 0.0;
		for (j = (i+1); j < n; j++)
		{
			sum += a[i][j] * x[j];
		}
		x[i] = (a[i][n] - sum) / a[i][i];
	}
	for (k = (n-2); k >= 0; k--)
	{
		al = x[pivcol[k][1]];
		x[pivcol[k][1]] = x[pivcol[k][0]];
		x[pivcol[k][0]] = al;
	}
}

void gauss::gauss_output()
{
	ofstream fout("gauss.out");
	fout << "\n结果是：" << endl;
	for (i = 0; i < n; i++)
	{
		fout << "\nx[" << i << "] = " << x[i] << endl;
	}
	fout.close();
}