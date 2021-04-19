//��������������������˻������������˻���������ӡ������������
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
	cout << "\n���������������������1" << endl;
	cout << "\n�������������˻�������2" << endl;
	cout << "\n���������;���˻�������3" << endl;
	cout << "\nʵ������������ӣ�����4" << endl;
	cout << "\nʵ������������ˣ�����5" << endl;
	cout << "\n�������ѡ��1 - 5��";
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
		cout << "\n�������˴����ѡ��" << endl;
		exit(0);
	}
}

//���������������
void matrix::vector_dot()
{
	int i;
	double *x, *y;
	cout << "\n��������ά����";
	cin >> n;
	x = new double[n];
	y = new double[n];
	cout << "\n��������x�ĸ�������" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n����x[" << i << "] = ";
		cin >> x[i];
	}
	cout << "\n��������y�ĸ�������" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n����y[" << i << "] = ";
		cin >> y[i];
	}
	double sum = 0.0;
	for (i = 0; i < n; i++)
	{
		sum += x[i]*y[i];
	}
	cout << "\n�����" << sum << endl;
	delete[] x, y;
}

//�������������˻�����
void matrix::mat_vec()
{
	int i, j;
	double *x, *z;
	double **a;
	cout << "\n������������";
	cin >> n;
	x = new double[n];
	z = new double[n];
	a = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	cout << "\n��������Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n��������x��������" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n����x[" << i << "] = ";
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
	cout << "\n�˻������ǣ�" << endl;
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

//���������;���˻�����
void matrix::vec_mat()
{
	int j, k;
	double *x, *z;
	double **a;
	cout << "\n������������";
	cin >> n;
	x = new double[n];
	z = new double[n];
	a = new double*[n];
	for (k = 0; k < n; k++)
	{
		a[k] = new double[n];
	}
	cout << "\n��������x��������" << endl;
	for (k = 0; k < n; k++)
	{
		cout << "\n����x[" << k << "] = ";
		cin >> x[k];
	}
	cout << "\n��������Ԫ�أ�" << endl;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����a[" << k << "][" << j << "] = ";
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
	cout << "\n�˻������ǣ�" << endl;
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

//����������Ӻ���
void matrix::mat_add()
{
	int i, j;
	double **a, **b, **c;
	cout << "\n������������";
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
	cout << "\n�������A��Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n�������B��Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����b[" << i << "][" << j << "] = ";
			cin >> b[i][j];
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	cout << "\n��������ǣ�" << endl;
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

//����������˺���
void matrix::mat_mult()
{
	int i, j, k;
	double **a, **b, **c;
	cout << "\n������������";
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
	cout << "\n�������A��Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	cout << "\n�������B��Ԫ�أ�" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "\n����b[" << i << "][" << j << "] = ";
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
	cout << "\n��������ǣ�" << endl;
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