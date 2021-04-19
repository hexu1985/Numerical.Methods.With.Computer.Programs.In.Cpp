//������ѡ��Ԫ�ʹ�ǰ��������LU�ֽ�
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
	cout << "\n���뷽�̸�����";
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
			cout << "\n����a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	for (i = 0; i < n; i++)
	{
		cout << "\n����b[" << i << "] = ";
		cin >> b[i];
	}
	cout << "\n������С��Ԫ�أ�";
	cin >> eps;
}

void lu::lu_decomposition()
{
//LU�ֽ�
	for (j = 0; j < n; j++)
	{
//���������Ǿ���U
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
//���������Ǿ���L
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
			cout << "\n����������죬ʧ��..." << endl;
			exit(0);
		}
//��ѡ��Ԫ
		if (pivrow[j] != j)
		{
			for (k = 0; k < n; k++)
			{
				a1 = a[pivrow[j]][k];
				a[pivrow[j]][k] = a[j][k];
				a[j][k] = a1;
			}
		}
//���������Ǿ���L
		if (j != (n-1))
		{
			for (i = (j+1); i < n; i++)
			{
				a[i][j] /= a[j][j];
			}
		}
	}
//��ǰ������룬�ȼ���LY = B
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
//�ټ���UX = Y
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
	cout << "\n����ǣ�" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << b[i] << endl;
	}
}