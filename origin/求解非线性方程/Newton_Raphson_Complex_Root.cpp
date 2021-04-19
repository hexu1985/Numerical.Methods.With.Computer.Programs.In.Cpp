//用Newton-Raphson法求解非线性方程复根
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class raphson
{
private:
	int iteration, flag;
	double eps, error1, error2, f_u, f_v, f_u_alpha, f_u_beta;
	double alpha_new, alpha_old, beta_new, beta_old;
	double term1, term2, term3, term4, term5;

public:
	raphson()
	{
		iteration = 0;
		flag = 1;
	}
	void solution();
	double u(double a1, double b1)
	{
		f_u = a1 * a1 - b1 * b1 - 2 * a1 + 2;
		return f_u;
	}
	double v(double a2, double b2)
	{
		f_v = 2 * a2 * b2 - 2 * b2;
		return f_v;
	}
	double u_alpha(double a3, double b3)
	{
		f_u_alpha = 2 * a3 - 2;
		return f_u_alpha;
	}
	double u_beta(double a4, double b4)
	{
		f_u_beta = -2 * b4;
		return f_u_beta;
	}
};

void main()
{
	raphson nonlinear;
	nonlinear.solution();
}

void raphson::solution()
{
	cout << "\n输入alpha初值：";
	cin >> alpha_old;
	cout << "\n输入beta初值：";
	cin >> beta_old;
	cout << "\n输入公差：";
	cin >> eps;
	do
	{
		iteration++;
		term1 = u(alpha_old, beta_old);
		term2 = v(alpha_old, beta_old);
		term3 = u_alpha(alpha_old, beta_old);
		term4 = u_beta(alpha_old, beta_old);
		term5 = term3 * term3 + term4 * term4;
		if (term5 == 0)
		{
			cout << "\n遇到了被0除，程序中断..." << endl;
			exit(0);
		}
		alpha_new = alpha_old + (term2 * term4 - term1 * term3) / term5;
		beta_new = beta_old - (term2 * term3 + term1 * term4) / term5;
		error1 = fabs(term1);
		error2 = fabs(term2);
		if ((error1 < eps) && (error2 < eps))
		{
			flag = 0;
		}
		alpha_old = alpha_new;
		beta_old = beta_new;
	}while (flag == 1);
	cout << "\n解是：" << endl;
	cout << "\n实部：" << alpha_new << endl;
	cout << "\n虚部：" << beta_new << endl;
	cout << "\n在第" << iteration << "次迭代收敛。" << endl;
}