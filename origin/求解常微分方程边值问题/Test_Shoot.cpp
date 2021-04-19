//用试射法求解边值问题
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

class s_ode
{
private:
	int i, j, l, n;
	double a, b, c, d, h, x, x1, xi, xf;
	double *b1, *b2, *b3, *g, *y, *y1;

public:
	s_ode()
	{
		a = (sqrt(2.0) - 1) / 2;
		b = (2 - sqrt(2.0)) / 2;
		c = -sqrt(2.0) / 2;
		d = 1 + sqrt(2.0) / 2;
	}
	void func (double p, double *q, double *r)
	{
		r[0] = q[1];
		r[1] = q[2];
		r[2] = -q[0] * q[0] * q[1] - q[0] * cos(p) + sin(p) * sin(p);
	}
	void solution();
	~s_ode()
	{
		delete[] b1, b2, b3, g, y, y1;
	}
};

void main()
{
	s_ode shooting;
	shooting.solution();
}

void s_ode::solution()
{
	n = 3;
	b1 = new double[n];
	b2 = new double[n];
	b3 = new double[n];
	g = new double[n];
	y = new double[n];
	y1 = new double[n];
	l = 1000;
	xi = 0.0;
	xf = 30.0;
	for (i = 0; i < n; i++)
	{
		cout << "\n输入y[" << i << "] = ";
		cin >> y[i];
	}
	h = (xf - xi) / l;
	x = xi;
	ofstream fout("shooting.txt");
	fout.precision(4);
	cout.precision(4);
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < n; j++)
		{
			y1[j] = y[j];
		}
		x1 = x;
		func(x, y, g);
		for (j = 0; j < n; j++)
		{
			b1[j] = g[j];
			y[j] = y1[j] + h * g[j] / 2;
		}
		x = x1 + h / 2;
		func(x, y, g);
		for (j = 0; j < n; j++)
		{
			b2[j] = g[j];
			y[j] = y1[j] + h * (a * b1[j] + b * g[j]);
		}
		func(x, y, g);
		for (j = 0; j < n; j++)
		{
			b3[j] = g[j];
			y[j] = y1[j] + h * (c * b2[j] + d * g[j]);
		}
		x = x1 + h;
		func(x, y, g);
		for (j = 0; j < n; j++)
		{
			y[j] = y1[j] + h * (b1[j] + g[j] + 2 * (b * b2[j] + d * b3[j])) / 6;
		}
		fout << x << setw(10) << y[0] << endl;
		cout << x << setw(10) << y[0] << endl;
	}
	fout.close();
}