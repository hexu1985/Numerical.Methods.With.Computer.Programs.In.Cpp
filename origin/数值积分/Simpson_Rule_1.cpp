//实现Simpson 3/8法则
#include <iostream>
#include <math.h>

using namespace std;

class simpson2
{
private:
	int n, k;
	double a, b, f, integral, interval, one_third_interval;
	double sum_term1, sum_term2, sum_term3, x;

public:
	double func(double x)
	{
		f = (5.093e-5 * exp(2 * x)) / pow((1 + x * x), 2);
		return f;
	}
	void integration();
};

void main()
{
	simpson2 simp2;
	simp2.integration();
}

void simpson2::integration()
{
	cout << "\n输入上限和下限：";
	cin >> b >> a;
	cout << endl << "\n输入你要使用simpson 3/8法则的数目（即等分数）：";
	cin >> n;
	interval = (b - a) / n;
	one_third_interval = interval / 3.0;
	sum_term1 = 0.0;
	sum_term2 = 0.0;
	sum_term3 = 0.0;
	for (k = 1; k < n; k++)
	{
		x = a + k * interval;
		sum_term1 += func(x);
		sum_term2 += func(x + one_third_interval);
		sum_term3 += func(x + 2 * one_third_interval);
	}
	integral = (2 * sum_term1 + 3 * sum_term2 + 3 * sum_term3 - func(a) + func(b)) * (3 * one_third_interval / 8);
	cout << endl << "积分值 = " << integral << endl;
}