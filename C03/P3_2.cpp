// P3_2.cpp
// 全选主元Gauss消去法程序

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

class gauss
{
	private:
		int i, j, k, n, *pivrow, **pivcol;
		double eps, pivot, sum, aik, al, *x, **a;

	public:
        void gauss_input();         // 数据输入的函数声明
        void gauss_elimination();   // 消去法的函数声明
        void gauss_output();        // 结果输出的函数声明
        ~gauss()                    // 释放存储器
		{
			delete [] x;
			delete [] pivrow;
			for (i=0; i<n; i++) { delete [] a[i]; }
			delete [] a;
			for (i=0; i<n; i++) { delete [] pivcol[i]; }
			delete [] pivcol;
		}
};                                  // 类gauss结束

int main()                         // 主函数
{
    gauss solution;
    solution.gauss_input();         // 输入增广矩阵的系数
    solution.gauss_elimination();   // 执行Gauss消去法
    solution.gauss_output();        // 输出结果
    return 0;
}

void gauss::gauss_input()           // 数据输入函数
{
	ifstream fin("gauss.dat");
	fin >> n;						// 输入方程个数	
    x = new double[n];              // 动态分配存储器
	pivrow = new int[n];
	pivcol = new int *[n];
	for (i=0; i<n; i++) { pivcol[i] = new int[2]; }
	a = new double *[n];
	for (i=0; i<n; i++) { a[i] = new double[n+1]; }
    for (i=0; i<n; i++)             // 输入系数矩阵的各元素
        for (j=0; j<n; j++)
        {
            fin >> a[i][j];
        }
    for (i=0; i<n; i++)             // 输入右端向量的各元素
    {
        fin >> a[i][n];
    }
    fin >> eps;
	fin.close();
}                                   // 输入段结束

void gauss::gauss_elimination()     // Gauss消去法函数
{
	for (k=0; k<(n-1); k++)
	{
		pivot = fabs(a[k][k]);
		pivrow[k] = k;
		pivcol[k][0] = k; pivcol[k][1] = k;
		for (i=k; i<n; i++)
			for (j=k; j<n; j++)
			{
				if (pivot<fabs(a[i][j]))
				{
					pivot = fabs(a[i][j]);
					pivrow[k] = i;
					pivcol[k][1] = j;
				}
			}
		if (pivot < eps)
		{
			cout << "\n矩阵可能奇异. 失败..." << endl;
			exit(0);
		}
		if (pivrow[k] != k)
		{
			for (j=k; j<(n+1); j++)
			{
				al = a[pivrow[k]][j]; a[pivrow[k]][j] = a[k][j];
				a[k][j] = al;
			}
		}
		if (pivcol[k][1] != k)
		{
			for (i=0; i<n; i++)
			{
				al = a[i][pivcol[k][1]]; a[i][pivcol[k][1]] = a[i][k];
				a[i][k] = al;
			}
		}
		if (k != (n-1))
		{
			for (i=(k+1); i<n; i++)
			{
				aik = a[i][k];
				for (j=k; j<(n+1); j++)
				{
					a[i][j] -= aik*a[k][j]/a[k][k];
				}
			}
		}
	}
	x[n-1] = a[n-1][n]/a[n-1][n-1];		// 回代
	for (i=(n-2); i>=0; i--)
	{
		sum = 0.0;
		for (j=(i+1); j<n; j++)
		{
			sum += a[i][j]*x[j];
		}
		x[i] = (a[i][n]-sum)/a[i][i];
	}
	for (k=(n-2); k>=0; k--)			// 恢复结果
	{
		al = x[pivcol[k][1]]; x[pivcol[k][1]] = x[pivcol[k][0]];
		x[pivcol[k][0]] = al;
	}
}

void gauss::gauss_output()
{
	ofstream fout("gauss.out");
    fout << "\n结果是: " << endl;
    for (i=0; i<n; i++)
    { fout << "\nx[" << i << "] = " << x[i] << endl; }
	fout.close();
}
