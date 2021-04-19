//用Runge_Kutta_Fehlberg法求解微分方程
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

class rkf
{
private:
	int flag;
	double eps, error, f, h, hnew, x, xf, y, yold;
	double k1, k2, k3, k4, k5, k6;

public:
	rkf()
	{
		flag = 0;
	}
	double func(double z, double t)
	{
		f = t * t - t * t * t;
		return f;
	}
	void step_adjust();
	double cash_karp(double, double, double);
};

void main()
{
	rkf fehlberg;
	fehlberg.step_adjust();
}

void rkf::step_adjust()
{
	cout << "\n输入x0：";
	cin >> x;
	cout << "\n输入y0：";
	cin >> y;
	cout << "\n输入xf：";
	cin >> xf;
	cout << "\n输入eps：";
	cin >> eps;
	h = xf - x;
	eps = fabs(eps);
	ofstream fout("Fehlberg.txt");
	fout.precision(4);
	cout.precision(4);
	do
	{
		yold = y;
		y = cash_karp(x, yold, h);
		if (error > eps)
		{
			do
			{
				hnew = h * pow(eps / error, 0.25);
				y = cash_karp(x, yold, hnew);
				h = hnew;
			}while (error > eps);
		}
		else
		{
			do
			{
				hnew = h * pow(eps / error, 0.2);
				y = cash_karp(x, yold, hnew);
				if (error < eps)
				{
					h = hnew;
				}
				else
				{
					y = cash_karp(x, yold, h);
					break;
				}
			}while (error < eps);
		}
		if ((x + h) >= xf)
		{
			h = xf - x;
			y = cash_karp(x, yold, h);
			flag = 1;
		}
		cout << (x + h) << setw(10) << y << setw(15) << error << endl;
		fout << (x + h) << setw(10) << y << setw(15) << error << endl;
		x += h;
	}while (flag == 0);
	fout.close();
}

double rkf::cash_karp(double p, double q, double r)
{
	k1 = r * func(p, q);
	k2 = r * func((p + r / 5), (q + k1 / 5));
	k3 = r * func((p + 3 * r / 10), (q + 3 * k1 / 40 + 9 * k2 / 40));
	k4 = r * func((p + 3 * r / 5), (q + 3 * k1 / 10 - 9 * k2 / 10 + 6 * k3 / 5));
	k5 = r * func((p + r), (q - 11 * k1 / 54 + 5 * k2 / 2 - 70 * k3 / 27 + 35 * k4 / 27));
	k6 = r * func((p + 7 * r / 8), (q + 1631 * k1 / 55296 + 175 * k2 / 512 + 575 * k3 / 13824 + 44275 * k4 / 110592 + 253 * k5 / 4096));
	q += 37 * k1 / 378 + 250 * k3 / 621 + 125 * k4 / 594 + 512 * k6 / 1771;
	error = fabs(k1 * (2825.0 / 27648 - 37.0 / 378) + k3 * (18575.0 / 48384 - 250.0 / 621) + k4 * (13525.0 / 55296 - 125.0 / 594) + (k5 * 277 / 14336) + k6 * (1.0 / 4 - 512.0 / 1771));
	return q;
}