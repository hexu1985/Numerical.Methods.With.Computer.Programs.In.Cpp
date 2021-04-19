//�ø��߷��������Է���
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
	cout << "\n�����ʼ��ֵx0��x1��";
	cin >> x_old1 >> x_old2;
	cout << "\n���빫��";
	cin >> eps;
	if (fabs(function(x_old1)) < eps)
	{
		cout << "\n���ǣ�" << x_old1 << endl;
		exit(0);
	}
	if (fabs(function(x_old2)) < eps)
	{
		cout << "\n���ǣ�" << x_old2 << endl;
		exit(0);
	}
	do
	{
		iteration++;
		if (x_old1 == x_old2)
		{
			cout << "\n�����˴���x(i) = x(i-1)���쳣�ж�..." << endl;
			exit(0);
		}
		x_new = x_old2 - (function(x_old2) * (x_old2 - x_old1)) / (function(x_old2) - function(x_old1));
		error = fabs(function(x_new));
		x_old1 = x_old2;
		x_old2 = x_new;
	}while (error >= eps);
	cout << "\n���ǣ�" << x_new << endl;
	cout << "\n������" << iteration << "�ε���" << endl;
}