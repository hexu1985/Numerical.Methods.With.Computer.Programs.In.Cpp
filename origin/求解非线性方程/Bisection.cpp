//�öԷַ��������Է���
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class bisection
{
private:
	int iteration;
	double eps, error, f, f_low, f_high, f_new, x_low, x_high, x_new;

public:
	bisection()
	{
		iteration = 0;
	}
	void solution();
	double function(double x)
	{
		f = x - cos(x);
		return f;
	}
};

void main()
{
	bisection bisect;
	bisect.solution();
}

void bisection::solution()
{
	cout << "\n�������ޣ�";
	cin >> x_low;
	cout << "\n�������ޣ�";
	cin >> x_high;
	f_low = function(x_low);
	f_high = function(x_high);
	if ((f_low * f_high) > 0)
	{
		cout << "\n����Ĺ��ࡣ" << endl;
		exit(0);
	}
	cout << "\n���빫�";
	cin >> eps;
	if (fabs(f_low) < eps)
	{
		cout << "\n���ǣ�" << x_low << endl;
		exit(0);
	}
	if (fabs(f_high) < eps)
	{
		cout << "\n���ǣ�" << x_high << endl;
		exit(0);
	}
	do
	{
		iteration++;
		x_new = 0.5 * (x_low + x_high);
		f_new = function(x_new);
		error = fabs(f_new);
		if ((f_new * f_low) < 0)
		{
			x_high = x_new;
		}
		else
		{
			x_low = x_new;
			f_low = f_new;
		}
	}while (error >= eps);
	cout << "\n���ǣ�" << x_new << endl;
	cout << "\n������" << iteration << "�ε���" << endl;
}