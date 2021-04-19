//三次样条函数拟合数据

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <process.h>

using namespace std;

class cspline
{
private:
	int i, n, low_limit, high_limit;
	double a, b, h, r, term, term1, term2, term3, term4, term5, term6, xs, ys;
	double* x, * y, * v, * gamma, * c, * beta;

public:
	void input();
	void spline_deriv();
	void spline_interp();
	void spline_plot();
	~cspline()
	{
		delete[] x, y, v, gamma, c, beta;
	}
};

void main()
{
	cspline spline;
	spline.input();
	spline.spline_deriv();
	spline.spline_plot();
}

//数据输入函数
void cspline::input()
{
	ifstream fin("cspline.txt");
	fin >> n;
	x = new double[n];
	y = new double[n];
	v = new double[n];
	gamma = new double[n-2];
	c = new double[n-2];
	beta = new double[n-2];
	for (i = 0; i < n; i++)
	{
		fin >> x[i] >> y[i];
	}
	fin.close();
	for (i = 1; i < n; i++)
	{
		if (x[i] <= x[i-1])
		{
			cout << "\n错误，以x升序输入数据。" << endl;
			exit(0);
		}
	}
}

//计算二阶导数的函数
void cspline::spline_deriv()
{
	v[0] = 0.0;
	v[n-1] = 0.0;
	b = 2.0;
	for (i = 1; i < (n-1); i ++)
	{
		term1 = x[i] - x[i-1];
		term2 = x[i+1] - x[i-1];
		term3 = y[i+1] - y[i];
		term4 = y[i] - y[i-1];
		term5 = x[i+1] - x[i];
		a = term1 / term2;
		r = (6.0 / term2) * (term3 / term5 - term4 / term1);
		c[i-1] = 1.0 - a;
		if (i == 1)
		{
			beta[i - 1] = b;
			gamma[i - 1] = r / beta[i-1];

		}
		else
		{
			beta[i - 1] = b - a * c[i-2] / beta[i-2];
			gamma[i - 1] = (r - a * gamma[i-2]) / beta[i-1];
		}
	}
	for (i = (n-2); i > 1; i--)
	{
		v[i] = gamma[i-1] - c[i-1] * v[i+1] / beta[i-1];
	}
	for (i = 0; i < n; i++)
	{
		cout << "\nv[" << i << "] = " << v[i] << endl;
	}
}

//画图函数
void cspline::spline_plot()
{
	h = 0.001 * (x[n-1] - x[0]);
	xs = x[0];
	ofstream fout("cspline.res");
	fout.precision(4);
	do
	{
		spline_interp();
		fout << xs << setw(15) << ys << endl;
		xs += h;
	}while (xs <= x[n-1]);
	fout.close();
}

//计算三次样条函数
void cspline::spline_interp()
{
	low_limit = 0;
	high_limit = n-1;
	while((high_limit - low_limit) > 1)
	{
		i = (high_limit + low_limit) / 2;
		if (x[i] > xs)
		{
			high_limit = i;
		}
		else
		{
			low_limit = i;
		}
	}
	term = x[high_limit] - x[low_limit];
	term1 = (x[high_limit] - xs) / term;
	term2 = (xs - x[low_limit]) / term;
	term3 = term1 * y[low_limit];
	term4 = term2 * y[high_limit];
	term5 = (pow(term1, 3) - term1) * v[low_limit];
	term6 = (pow(term2, 3) - term2) * v[high_limit];
	ys = term3 + term4 + ((term5 + term6) * pow(term, 2)) / 6;
}