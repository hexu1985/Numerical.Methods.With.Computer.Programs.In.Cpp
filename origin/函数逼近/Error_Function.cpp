//有理逼近的误差函数
#include <iostream>
#include <math.h>

using namespace std;

class erf
{
private:
	int i, n;
	double F, p, t, x;
	double a[5];

public:
	void err_fn();
};

void main()
{
	erf err0;
	err0.err_fn();
}

void erf::err_fn()
{
	n = 4;
	a[0] = 0.254829592;
	a[1] = -0.284496736;
	a[2] = 1.421413741;
	a[3] = -1.453152027;
	a[4] = 1.061405429;
	cout << "\n输入x（x >= 0） = ";
	cin >> x;
	p = 0.3275911;
	t = 1 / (1 + p * x);
	F = a[n];
	for (i = (n - 1); i >= 0; i--)
	{
		F = F * t + a[i];
	}
	F *= t;
	F = 1 - F * exp(-x * x);
	cout << "\n在" << x << "点的误差函数值 = " << F << endl;
}