//Gauss求积法五点公式
#include <iostream>
#include <math.h>

using namespace std;

class quadrature
{
private:
	int i;
	double a, b, f, integral, sum;
	double w[5], x[5];

public:
	double func(double r)
	{
		f = 8.168 * r * pow((1 - r / 2.5), 0.17);
		return f;
	}
	void integration();
};

void main()
{
	quadrature legendre;
	legendre.integration();
}

void quadrature::integration()
{
	w[0] = 0.2369269;
	w[1] = 0.4786287;
	w[2] = 0.5688889;
	w[3] = 0.4786287;
	w[4] = 0.2369269;
	x[0] = -0.90617985;
	x[1] = -0.53846931;
	x[2] = 0.0;
	x[3] = 0.53846931;
	x[4] = 0.90617985;
	cout << "\n输入下限和上限：";
	cin >> a >> b;
	sum = 0.0;
	for (i = 0; i < 5; i++)
	{
		sum += w[i] * func((x[i] * (b - a) + b + a) / 2);
	}
	integral = ((b - a) / 2) * sum;
	cout << endl << "积分值 = " << integral << endl;
}