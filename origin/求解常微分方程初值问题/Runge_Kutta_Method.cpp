//用RKG法求解微分方程
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class rkg
{
private:
	int i, n;
	double a, b, c, d, f, h, k1, k2, k3, k4, x, xf, y;

public:
	double func(double z, double t)
	{
		f = 0.9 * t - 0.09 * t * t;
		return f;
	}
	void solution();
};

void main()
{
	rkg runge;
	runge.solution();
}

void rkg::solution()
{
	cout << "\n输入初始条件：" << endl;
	cout << "\n输入x0：";
	cin >> x;
	cout << "\n输入y0：";
	cin >> y;
	cout << "\n输入xf：";
	cin >> xf;
	cout << "\n输入等分数：";
	cin >> n;
	h = (xf - x) / n;
	a = (sqrt(2.0) - 1) / 2;
	b = (2 - sqrt(2.0)) / 2;
	c = -sqrt(2.0) / 2;
	d = 1 + sqrt(2.0) / 2;
	cout.precision(4);
	for (i = 0; i < n; i++)
	{
		k1 = h * func(x, y);
		k2 = h * func((x + h / 2), (y + k1 / 2));
		k3 = h * func((x + h / 2), (y + a * k1 + b * k2));
		k4 = h * func((x + h), (y + c * k2 + d * k3));
		y += (k1 + 2 * b * k2 + 2 * d * k3 + k4) / 6;
		cout << (x + h) << setw(10) << y << endl;
		x += h;
	}
}