//实现多步Euler法
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class multi_euler
{
private:
	int i, n;
	double f, h, x, x_last, yc, yc_old, yp;

public:
	double func(double z, double t)
	{
		f = -0.3 * pow((t - 50), 1.25);
		return f;
	}
	void pc();
};

void main()
{
	multi_euler multistep_pc;
	multistep_pc.pc();
}

void multi_euler::pc()
{
	cout << "\n输入初始条件：" << endl;
	cout << "\n输入x0：";
	cin >> x;
	cout << "\n输入y0：";
	cin >> yc;
	cout << "\n输入y(-1)：";
	cin >> yc_old;
	cout << "\n输入y需要的x值：";
	cin >> x_last;
	cout << "\n输入等分数：";
	cin >> n;
	h = (x_last - x) / n;
	cout.precision(7);
	for (i = 0; i < n; i++)
	{
		yp = yc_old + 2 * h * func(x, yc);
		yc_old = yc;
		yc += 0.5 * h * (func(x, yc) + func((x + h), yp));
		x += h;
		cout << x << setw(12) << yc << endl;
	}
}