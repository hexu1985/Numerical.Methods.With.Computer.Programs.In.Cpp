//计算给定点处的一阶和二阶导数
#include <iostream>
#include <math.h>

using namespace std;

class deriv
{
private:
	int k;
	double d1, d1_1, d1_2, d2, d2_1, d2_2, d1_new, d2_new;
	double f_x, f_xhm, f_x2hm, f_xhp, f_x2hp, h, x;

public:
	double func(double y)
	{
		double f = 1 / sqrt(y) - 1.77 * log(1e4 * sqrt(y)) + 0.5;
		return f;
	}
	void diffn();
};

void main()
{
	deriv differentiate;
	differentiate.diffn();
}

void deriv::diffn()
{
	cout << "\n输入要计算导数的点：";
	cin >> x;
	cout << "\n输入步长h：";
	cin >> h;
	for (k = 0; k <= 1; k++)
	{
		f_x = func(x);
		f_xhp = func(x + h);
		f_x2hp = func(x + 2 * h);
		f_xhm = func(x - h);
		f_x2hm = func(x - 2 * h);
		d1 = (-f_x2hp + 8 * f_xhp - 8 * f_xhm + f_x2hm) / (12 * h);
		d2 = (-f_x2hp + 16 * f_xhp - 30 * f_x + 16 * f_xhm - f_x2hm) / (12 * h * h);
		if (k == 0)
		{
			d1_1 = d1;
			d2_1 = d2;
		}
		if (k == 1)
		{
			d1_2 = d1;
			d2_2 = d2;
		}
		h /= 2.0;
	}
	d1_new = (16 * d1_2 - d1_1) / 15;
	d2_new = (16 * d2_2 - d2_1) / 15;
	cout << "\n在" << x << "点的一阶导数 = " << d1_new << endl;
	cout << "\n在" << x << "点的二阶导数 = " << d2_new << endl;
}