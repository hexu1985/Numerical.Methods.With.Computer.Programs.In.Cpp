//实现Milne预报-校正法
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class milne
{
private:
	int i, n;
	double f, h, x, x_last, y, y1, y2, y3, yc, yp;
	double f0, f1, f2;

public:
	double func(double z, double t)
	{
		f = -t + sin(z);
		return f;
	}
	void pc();
};

void main()
{
	milne cotes_pc;
	cotes_pc.pc();
}

void milne::pc()
{
	cout << "\n输入初始条件：";
	cout << "\n输入x0：";
	cin >> x;
	cout << "\n输入y0：";
	cin >> y;
	cout << "\n输入y需要的x值：";
	cin >> x_last;
	cout << "\n输入等分数：";
	cin >> n;
	h = (x_last - x) / n;
	cout << "\n输入在x = " << (x - h) << "处的y(-1)：";
	cin >> y1;
	cout << "\n输入在x = " << (x - 2 * h) << "处的y(-2)：";
	cin >> y2;
	cout << "\n输入在x = " << (x - 3 * h) << "处的y(-3)：";
	cin >> y3;
	f0 = func(x, y);
	f1 = func((x - h), y1);
	f2 = func((x - 2 * h), y2);
	for (i = 0; i < n; i++)
	{
		yp = y3 + (4 * h / 3) * (2 * f2 - f1 + 2 * f0);
		y3 = y2;
		y2 = y1; 
		y1 = y;
		y = y2 + (h / 3) * (f1 + 4 * f0 + func((x + h), yp));
		f2 = f1; 
		f1 = f0;
		x += h;
		f0 = func(x, y);
		cout << x << setw(15) << y << endl;
	}
}