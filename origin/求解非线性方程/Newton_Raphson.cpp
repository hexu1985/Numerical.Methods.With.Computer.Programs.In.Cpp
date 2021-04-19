//��Newton_Raphson���������Է���
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class raphson
{
private:
	int iteration;
	double eps, error, f, df, x_new, x_old;
	double pi, sigma, epsilon, h, T_a, T_w, D, I_sq_R;

public:
	raphson()
	{
		iteration = 0;
		pi = 3.14159;
		sigma = 5.67e-8;
		epsilon = 0.8;
		h = 25;
		T_a = 298;
		T_w = 298;
		D = 0.12;
		I_sq_R = 150;
	}
	void solution();
	double function(double x)
	{
		f = pi * D * (h * (x - T_a) + epsilon * sigma * (pow(x, 4) - pow(T_w, 4))) - I_sq_R;
		return f;
	}
	double deriv_function(double y)
	{
		df = pi * D * (h + 4 * epsilon * sigma * pow(y, 3));
		return df;
	}
};

void main()
{
	raphson nonlinear;
	nonlinear.solution();
}

void raphson::solution()
{
	cout << "\n�����ʼ��ֵ��";
	cin >> x_old;
	cout << "\n���빫�";
	cin >> eps;
	if (fabs(function(x_old)) < eps)
	{
		cout << "\n���ǣ�" << x_old << endl;
		exit(0);
	}
	do
	{
		iteration++;
		x_new = x_old - function(x_old) / deriv_function(x_old);
		error = fabs(function(x_new));
		x_old = x_new;
	}while (error >= eps);
	cout << "\n���ǣ�" << x_new << endl;
	cout << "\n������" << iteration << "�ε���" << endl;
}