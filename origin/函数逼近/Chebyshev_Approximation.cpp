//计算给定函数的Chebyshev逼近
#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

const double pi = 3.141592653589793;

class chebyshev
{
private:
	int div, i, j, n;
	double a, b, func, F, sum, t0, t1, temp, x, y;
	double *c, *f;

public:
	chebyshev()
	{
		div = 10;
	}
	double function(double z)
	{
		func = sin(z) * z * z * (z * z - 2);
		return func;
	}
	void cheb_coeff();
	void cheb_eval();
	~chebyshev()
	{
		delete[] c, f;
	}
};

void main()
{
	chebyshev cheby;
	cheby.cheb_coeff();
}

//计算逼近多项式的系数
void chebyshev::cheb_coeff()
{
	cout << "\n输入n：";
	cin >> n;
	c = new double[n];
	f = new double[n];
	cout << "\n输入区间下限和上限（即a和b）";
	cin >> a >> b;
	for (i =  0; i < n; i++)
	{
		y = cos(pi * (i + 0.5) / n);
		x = 0.5 * y * (b - a) + 0.5 * (b + a);
		f[i] = function(x);
	}
	for (i = 0; i < n; i++)
	{
		sum = 0.0;
		for (j = 0; j < n; j++)
		{
			sum += f[j] * cos(pi * i * (j + 0.5) / n);
		}
		c[i] = 2 * sum / n;
		cout << "\nc[" << i << "] = " << c[i] << endl;
	}
	cheb_eval();
}

void chebyshev::cheb_eval()
{
	ofstream fout("chebyshev.txt");
	x = a;
	for (i = 0; i <= div; i++)
	{
		y = (2 * x - a - b) / (b - a);
		t0 = 1.0;
		t1 = y;
		F = c[1] * t1 + 0.5 * c[0];
		for (j = 2; j < n; j++)
		{
			temp = t1;
			t1 = 2 * y * t1 - t0;
			t0 = temp;
			F += c[j] * t1;
		}
		fout << x << setw(15) << F << endl;
		x += (b - a) / div;
	}
	fout.close();
}