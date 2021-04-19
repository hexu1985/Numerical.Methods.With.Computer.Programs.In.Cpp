//向量点积、矩阵与向量乘积、向量与矩阵乘积、矩阵相加、矩阵相乘运算
#include <iostream>
#include <process.h>

using namespace std;

class matrix
{
private:
	int n;

public:
	void vector_dot();
	void mat_vec();
	void vec_mat();
	void mat_add();
	void mat_mult();
};

void main()
{
	int choice;
	cout << "\n计算两个向量点积，输入1" << endl;
	cout << "\n计算矩阵和向量乘积，输入2" << endl;
	cout << "\n计算向量和矩阵乘积，输入3" << endl;
	cout << "\n实现两个矩阵相加，输入4" << endl;
	cout << "\n实现两个矩阵相乘，输入5" << endl;
	cout << "\n输入你的选择（1 - 5）";
	cin >> choice;
	switch (choice)
	{
	case 1:
		matrix dot_prod;
		dot_prod.vector_dot();
		break;
	case 2:
		matrix mat_vec_prod;
		mat_vec_prod.mat_vec();
		break;
	case 3:
		matrix vec_mat_prod;
		vec_mat_prod.vec_mat();
		break;
	case 4:
		matrix matrix_addition;
		matrix_addition.mat_add();
		break;
	case 5:
		matrix matrix_multiplication;
		matrix_multiplication.mat_mult();
		break;
	default:
		cout << "\n你输入了错误的选择。" << endl;
		exit(0);
	}
}

//计算向量点积函数
void matrix::vector_dot()
{
	int i;
	double *x, *y;
	cout << "\n输入向量维数：";
	cin >> n;
	x = new double[n];
	y = new double[n];
	cout << "\n输入向量x的各分量：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	cout << "\n输入向量y的各分量：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入y[" << i << "] = ";
		cin >> y[i];
	}
	double sum = 0.0;
	for (i = 0; i < n; i++)
	{
		sum += x[i]*y[i];
	}
	cout << "\n点积是" << sum << endl;
	delete[] x, y;
}

//计算矩阵和向量乘积函数
void matrix::mat_vec()
{
	int i, j;
	double *x, *z;
	double **a;
	cout << "\n输入矩阵阶数：";
	cin >> n;
	x = new double[n];
	z = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	cout << "\n输入矩阵各元素：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n输入向量x各分量：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	for (i = 0; i < n; i++)
	{
		z[i] = 0.0;
		{
			for (j = 0; j < n; j++)
			{
				z[i] += a[i][j]*x[j];
			}
		}
	}
	cout << "\n乘积向量是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nz[" << i << "] = " << z[i] << endl;
	}
	delete[] x, z;
	for (i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

//计算向量和矩阵乘积函数
void matrix::vec_mat()
{
	int j, k;
	double *x, *z;
	double **a;
	cout << "\n输入矩阵阶数：";
	cin >> n;
	x = new double[n];
	z = new double[n];
	a = new double*[n];
	for (k = 0; k < n; k++)
	{
		a[k] = new double[n];
	}
	cout << "\n输入向量x各分量：" << endl;
	for (k = 0; k < n; k++)
	{
		cout << "\n输入x[" << k << "] = ";
		cin >> x[k];
	}
	cout << "\n输入矩阵各元素：" << endl;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << k << "][" << j << "] = ";
			cin >> a[k][j];
		}
	
	for (j = 0; j < n; j++)
	{
		z[j] = 0.0;
		{
			for (k = 0; k < n; k++)
			{
				z[j] += x[k]*a[k][j];
			}
		}
	}
	cout << "\n乘积向量是：" << endl;
	for (j = 0; j < n; j++)
	{
		cout << "\nz[" << j << "] = " << z[j] << endl;
	}
	delete[] x, z;
	for (k = 0; k < n; k++)
	{
		delete[] a[k];
	}
	delete[] a;
}

//两个矩阵相加函数
void matrix::mat_add()
{
	int i, j;
	double **a, **b, **c;
	cout << "\n输入矩阵阶数：";
	cin >> n;
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
	cout << "\n输入矩阵A各元素：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n输入矩阵B各元素：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入b[" << i << "][" << j << "] = ";
			cin >> b[i][j];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	cout << "\n结果矩阵是：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\nc[" << i << "][" << j << "] = " << c[i][j] << endl;
		}
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

//两个矩阵相乘函数
void matrix::mat_mult()
{
	int i, j, k;
	double **a, **b, **c;
	cout << "\n输入矩阵阶数：";
	cin >> n;
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
	cout << "\n输入矩阵A各元素：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n输入矩阵B各元素：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n输入b[" << i << "][" << j << "] = ";
			cin >> b[i][j];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			c[i][j] = 0.0;
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
	cout << "\n结果矩阵是：" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\nc[" << i << "][" << j << "] = " << c[i][j] << endl;
		}
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