//ʵ��Simpson 1/3����
#include <iostream>
#include <math.h>

using namespace std;

class simpson
{
private:
	int n, k;
	double a, b, f, half_interval, integral, interval, sum_even_terms;
	double sum_odd_terms, x;

public:
	double func(double t)
	{
		f = 2e3 * log(1e5 / (1e5 - 2e3 * t)) - 10 * t;
		return f;
	}
	void integration();
};

void main()
{
	simpson simp;
	simp.integration();
}

void simpson::integration()
{
	cout << "\n�������޺����ޣ�";
	cin >> b >> a;
	cout << "\n������Ҫʹ��simpson�������Ŀ�����ȷ�������";
	cin >> n;
	interval = (b - a) / n;
	half_interval = interval / 2.0;
	sum_even_terms  = 0.0;
	sum_odd_terms = 0.0;
	for (k = 1; k < n; k++)
	{
		x = a + k * interval;
		sum_even_terms += func(x);
		sum_odd_terms += func(x + half_interval);
	}
	integral = (2.0 * sum_even_terms + 4.0 * sum_odd_terms - func(a) + func(b)) * half_interval / 3.0;
	cout << endl << "����ֵ = " << integral << endl;
}