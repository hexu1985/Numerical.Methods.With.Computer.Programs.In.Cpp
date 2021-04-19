//Jacobi法确定对称矩阵特征值与特征向量
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

class jacobi
{
private:
	int flag, i, iteration, j, k, n;
	double csa, eps1, eps2, eps3, p, q, s1, s2, sna, spq, sum, temp;
	double *aik, *eigen, **a, **t;

public:
	jacobi()
	{
		iteration = 0;
		flag = 1;
		eps1 = 1e-10;
		eps2 = 1e-10;
		eps3 = 1e-5;
	}
	void solution();
	~jacobi()
	{
		delete[] aik;
		delete[] eigen;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
		for (i = 0; i < n; i++)
		{
			delete[] t[i];
		}
		delete[] t;
	}
};

void main()
{
	jacobi eigenpair;
	eigenpair.solution();
}

void jacobi::solution()
{
	cout << "\n输入矩阵阶数：";
	cin >> n;
	aik = new double[n];
	eigen = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	t = new double*[n];
	for (i = 0; i < n; i++)
	{
		t[i] = new double[n];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			t[i][j] = 0.0;
			a[i][j] = 0.0;
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	s1 = 0.0;
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		t[i][i] = 1.0;
		s1 += a[i][i]*a[i][i];
		sum += a[i][i];
	}
	do
	{
		iteration++;
		for (i = 0; i < (n-1); i++)
			for (j = (i+1); j < n; j++)
			{
				if (fabs(a[i][j]) < eps1)
				{
					a[i][j] = 0.0;
				}
				else
				{
					q = fabs(a[i][i] - a[j][j]);
					if (q > eps2)
					{
						p = 2 * a[i][j] * q / (a[i][i] - a[j][j]);
						spq = sqrt(p*p + q*q);
						csa = sqrt((1 + q/spq)/2);
						sna = p/(2*csa*spq);
					}
					else
					{
						csa = 0.707107;
						sna = csa;
					}
					for (k = 0; k < n; k++)
					{
						temp = t[k][i];
						t[k][i] = temp*csa + t[k][j]*sna;
						t[k][j] = temp*sna - t[k][j]*csa;
					}
					for (k = i; k < n; k++)
					{
						if (k > j)
						{
							temp = a[i][k];
							a[i][k] = csa*temp + sna*a[j][k];
							a[j][k] = sna*temp - csa*a[j][k];
						}
						else
						{
							aik[k] = a[i][k];
							a[i][k] = csa*aik[k] + sna*a[k][j];
							if (k == j)
							{
								a[j][k] = sna*aik[k] - csa*a[j][k];
							}
						}
					}
					aik[j] = sna*aik[i] - csa*aik[j];
					for (k = 0; k <= j; k++)
					{
						if (k <= i)
						{
							temp = a[k][i];
							a[k][i] = csa*temp + sna*a[k][j];
							a[k][j] = sna*temp - csa*a[k][j];
						}
						else
						{
							a[k][j] = sna*aik[k] - csa*a[k][j];
						}
					}
				}
			}
			s2 = 0.0;
			for (i = 0; i < n; i++)
			{
				eigen[i] = a[i][i];
				s2 += eigen[i]*eigen[i];
			}
			if (fabs(1 - s1/s2) < eps3)
			{
				flag = 0;
			}
			else
			{
				s1 = s2;
			}
	}while (flag == 1);
	for (i = 0; i < n; i++)
	{
		cout << "\n特征值[" << i << "] = " << eigen[i] << endl;
	}
	cout << "\n收敛于" << iteration << "次迭代。" << endl;
	cout << "\n输入矩阵的迹 = " << sum << endl;
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		sum += eigen[i];
	}
	cout << "\n特征值之和 = " << sum << endl;
	cout << "\n特征向量是：" << endl;
	cout.precision (4);
	for (j = 0; j < n; j++)
	{
		cout << "\n特征向量[" << j << "]: " << endl << endl;
		for (i = 0; i < n; i++)
		{
			cout << t[i][j] << setw(10);
		}
		cout << endl;
	}
}