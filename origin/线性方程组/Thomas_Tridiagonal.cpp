//Thomas��������ԽǷ�����
#include <iostream>
#include <math.h>

using namespace std;

class tridiagonal
{
private:
	int i, n;
	double *x, *a, *b, *c, *beta, *gamma, *r;

public:
	void input();
	void tridiagonal_solution();
	~tridiagonal()
	{
		delete[] x, a, b, c, beta, gamma, r;
	}
};

void main()
{
	tridiagonal tridiag;
	tridiag.input();
	tridiag.tridiagonal_solution();
}

void tridiagonal::input()
{
	cout << "\n���뷽�̵ĸ�����";
	cin >> n;
	a = new double[n-1];
	b = new double[n];
	c = new double[n-1];
	beta = new double[n];
	gamma = new double[n];
	r = new double[n];
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n����b[" << i << "] = ";
		cin >> b[i];
	}
	for (i = 0; i < (n-1); i++)
	{
		cout << "\n����c[" << i << "] = ";
		cin >> c[i];
	}
	for (i = 1; i < n; i++)
	{
		cout << "\n����a[" << i << "] = ";
		cin >> a[i-1];
	}
	for (i = 0; i < n; i++)
	{
		cout << "\n����r[" << i << "] = ";
		cin >> r[i];
	}
}

void tridiagonal::tridiagonal_solution()
{
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			beta[0] = b[0];
			gamma[0] = r[0] / beta[0];
		}
		else
		{
			beta[i] = b[i] - a[i-1]*c[i-1]/beta[i-1];
			gamma[i] = (r[i] - a[i-1]*gamma[i-1])/beta[i];
		}
	}
	x[n-1] = gamma[n-1];
	for (i = (n-2); i >= 0; i--)
	{
		x[i] = gamma[i] - c[i]*x[i+1]/beta[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}