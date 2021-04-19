//Newton_Cotes闭合积分公式
#include <iostream>
#include <math.h>

using namespace std;

class trapezoidal
{
private:
	int n, k;
	double a, b, f, h, integral, sum;

public:
	double func(double v)
	{
		f = 24.6 / (v - 0.065) - 5.5 / pow(v, 2);
		return f;
	}
	void integration();
};

void main()
{
	trapezoidal trape;
	trape.integration();
}

void trapezoidal::integration()
{
	cout << "\n输入下限和上限：";
	cin >> a >> b;
	cout << "\n输入你要的段数：";
	cin >> n;
	h = (b - a) / n;
	sum = 0.0;
	for (k = 1; k < n; k++)
	{
		sum += func(a + k * h);
	}
	integral = (h / 2.0) * (func(a) + 2.0 * sum + func(b));
	cout << endl << "积分值 = " << integral << endl;
}