//用试位法求解非线性方程
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class falsi
{
private:
	int iteration;
	double eps, error, f, f_low, f_high, f_new, x_low, x_high, x_new;
	double d, fric, Q, s, W;

public:
	falsi()
	{
		iteration = 0;
		fric = 0.01;
		Q = 10;
		s = 1e-3;
		W = 10;
	}
	void solution();
	double function(double d)
	{
		double term1 = d * pow((W * d / (W + 2 * d)), (2.0 / 3.0));
		double term2 = fric * Q / (W * sqrt(s));
		f = term1 - term2;
		return f;
	}
};

void main()
{
	falsi regula;
	regula.solution();
}

void falsi::solution()
{
	cout << "\n输入下限：";
	cin >> x_low;
	cout << "\n输入上限：";
	cin >> x_high;
	f_low = function(x_low);
	f_high = function(x_high);
	if ((f_low * f_high) > 0)
	{
		cout << "\n错误的归类。" << endl;
		exit(0);
	}
	cout << "\n输入公差：";
	cin >> eps;
	do
	{
		iteration++;
		x_new = (x_low * f_high - x_high * f_low) / (f_high - f_low);
		f_new = function(x_new);
		error = fabs(f_new);
		if ((f_new * f_low) < 0)
		{
			x_high = x_new;
		}
		else
		{
			x_low = x_new;
			f_low = f_new;
		}
	}while (error >= eps);
	cout << "\n解是：" << x_new << endl;
	cout << "\n收敛于" << iteration << "次迭代" << endl;
}