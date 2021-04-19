//Newton_Cotes�պϻ��ֹ�ʽ
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
	cout << "\n�������޺����ޣ�";
	cin >> a >> b;
	cout << "\n������Ҫ�Ķ�����";
	cin >> n;
	h = (b - a) / n;
	sum = 0.0;
	for (k = 1; k < n; k++)
	{
		sum += func(a + k * h);
	}
	integral = (h / 2.0) * (func(a) + 2.0 * sum + func(b));
	cout << endl << "����ֵ = " << integral << endl;
}