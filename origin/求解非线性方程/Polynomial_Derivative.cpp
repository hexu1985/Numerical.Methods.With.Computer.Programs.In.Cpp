//计算在指定点处多项式及其一阶导数值
#include <iostream>

using namespace std;

class horner
{
private:
	int i, n;
	double deriv, F, x;
	double *a;

public:
	horner()
	{
		deriv = 0;
	}
	void polynom();
	~horner()
	{
		delete[] a;
	}
};

void main()
{
	horner poly;
	poly.polynom();
}

void horner::polynom()
{
	cout << "\n输入多项式的阶数：";
	cin >> n;
	a = new double[n+1];
	cout << "\n输入多项式系数：a0 + a1 * x + a2 * x^2 + ..." << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "\n输入a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "\n输入计算多项式的所在点：";
	cin >> x;
	F = a[n];
	for (i = (n - 1); i >= 0; i--)
	{
		deriv = deriv * x + F;
		F = F * x + a[i];
	}
	cout << "\n多项式在" << x << "点处的值 = " << F << endl;
	cout << "\n多项式在" << x << "点处的导数值 = " << deriv << endl;
}