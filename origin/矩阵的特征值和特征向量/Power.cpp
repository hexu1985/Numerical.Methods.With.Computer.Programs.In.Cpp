//乘幂法计算矩阵绝对值最大特征值
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class power
{
private:
	int check, flag, i, j, iteration, n;
	double eps1, eps2, error1, error2, lambda, lambda_old, sum;
	double *y, *z, *z_old;
	double **a;

public:
	power()
	{
		iteration = 0;
		flag = 1;
	}
	void solution();
	double euclidean_norm(double *);
	~power()
	{
		delete[] y, z, z_old;
		for (i = 0; i < n; i++)
		{
			delete[] a[i];
		}
		delete[] a;
	}
};

void main()
{
	power eigenpair;
	eigenpair.solution();
}

void power::solution()
{
	cout << "输入矩阵阶数：";
	cin >> n;
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	y = new double[n];
	z = new double[n];
	z_old = new double[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n输入特征向量的初值。" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入初值z[" << i << "] = ";
		cin >> z[i];
	}
	cout << "\n输入特征值的容许误差";
	cin >> eps1;
	cout << "\n输入特征向量的容许误差";
	cin >> eps2;
	do
	{
		iteration++;
		check = 0;
		for (i = 0; i < n; i++)
		{
			sum = 0.0;
			for (j = 0; j < n; j++)
			{
				sum += a[i][j]*z[j];
			}
		y[i] = sum;
		}
		lambda = euclidean_norm(y);
		for (i = 0; i < n; i++)
		{
			z[i] = y[i] / lambda;
		}
		if (iteration > 1)
		{
			error1 = fabs((lambda - lambda_old) / lambda);
			for (i = 0; i < n; i++)
			{
				error2 = fabs((z[i] - z_old[i]) / z[i]);
				if (error2 >= eps2)
				{
					check = 1;
				}
			}
			if ((error1 < eps1) && (check == 0))
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			lambda_old = lambda;
			for (i = 0; i < n; i++)
			{
				z_old[i] = z[i];
			}
		}
		if (iteration > 1000)
		{
			cout << "\n1000次迭代不收敛，失败..." << endl;
			exit(0);
		}
	}while (flag == 1);
	cout << "\n绝对值最大的特征值 = " << lambda << endl;
	cout << "\n对应特征向量的各分量是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nz[" << i << "] = " << z[i] << endl;
	}
	cout << "\n收敛于" << iteration << "次迭代。" << endl;
}

//计算向量欧几里得范数的函数
double power::euclidean_norm(double* x)
{
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		sum += x[i]*x[i];
	}
	sum = sqrt(sum);
	return(sum);
}