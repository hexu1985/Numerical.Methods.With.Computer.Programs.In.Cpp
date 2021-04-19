//用割线法求解非线性方程
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class secant
{
private:
	int iteration;
	double eps, error, f, x_new, x_old1, x_old2;

public:
	secant()
	{
		iteration = 0;
	}
	void solution();
	double function(double x)
	{
		f = 1.55 * pow(x, -0.5) - 7.2 * x + 8.1 * x * x - 4 * pow(x, 3) - 1.3;
		return f;
	}
};

void main()
{
	secant nonlinear;
	nonlinear.solution();
}

void secant::solution()
{
	cout << "\n输入初始估值x0和x1：";
	cin >> x_old1 >> x_old2;
	cout << "\n输入公差";
	cin >> eps;
	if (fabs(function(x_old1)) < eps)
	{
		cout << "\n解是：" << x_old1 << endl;
		exit(0);
	}
	if (fabs(function(x_old2)) < eps)
	{
		cout << "\n解是：" << x_old2 << endl;
		exit(0);
	}
	do
	{
		iteration++;
		if (x_old1 == x_old2)
		{
			cout << "\n遇到了错误x(i) = x(i-1)，异常中断..." << endl;
			exit(0);
		}
		x_new = x_old2 - (function(x_old2) * (x_old2 - x_old1)) / (function(x_old2) - function(x_old1));
		error = fabs(function(x_new));
		x_old1 = x_old2;
		x_old2 = x_new;
	}while (error >= eps);
	cout << "\n解是：" << x_new << endl;
	cout << "\n收敛于" << iteration << "次迭代" << endl;
}