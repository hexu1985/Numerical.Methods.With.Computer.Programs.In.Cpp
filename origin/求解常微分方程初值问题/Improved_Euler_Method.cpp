//ʵ��EulerԤ��_У����
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class euler
{
private:
	int i, n;
	double f, h, x, x_last, yc, yp;

public:
	double func(double z, double t)
	{
		f = (1 + z) * t * t / 2;
		return f;
	}
	void pc();
};

void main()
{
	euler predictor_corrector;
	predictor_corrector.pc();
}

void euler::pc()
{
	cout << "\n�����ʼ������" << endl;
	cout << "\n����x0��";
	cin >> x;
	cout << "\n����y0��";
	cin >> yc;
	cout << "\n����y��Ҫ��xֵ��";
	cin >> x_last;
	cout << "\n����ȷ�����";
	cin >> n;
	h = (x_last - x) / n;
	for (i = 0; i < n; i++)
	{
		yp = yc + h * func(x, yc);
		yc += 0.5 * h * (func(x, yc) + func((x + h), yp));
		x += h;
		cout.precision(10);
		cout << x << setw(15) << yc << endl;
	}
}