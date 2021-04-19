//����δ��뷨�������Է���
#include <iostream>
#include <math.h>
#include <process.h>

using namespace std;

class successive
{
private:
	int iteration;
	double eps, error, f, x_new, x_old;

public:
	successive()
	{
		iteration = 0;
	}
	void solution();
	double function(double x)
	{
		f = 0.3 * exp(x);
		return f;
	}
};

void main()
{
	successive substitution;
	substitution.solution();
}

void successive::solution()
{
	cout << "\n�����ʼ��ֵ��";
	cin >> x_old;
	cout << "\n���빫�";
	cin >> eps;
	if (fabs(x_old - function(x_old)) < eps)
	{
		cout << "\n���ǣ�" << x_old << endl;
		exit(0);
	}
	do
	{
		iteration++;
		x_new = function(x_old);
		error = fabs(x_new - function(x_new));
		x_old = x_new;
	}while (error >= eps);
	cout << "\n���ǣ�" << x_new << endl;
	cout << "\n������" << iteration << "�ε���" << endl;
}