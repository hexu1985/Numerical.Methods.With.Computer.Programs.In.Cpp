//当一个零点已知时降低多项式阶的综合除法
#include <iostream>

using namespace std;

class synthetic
{
private:
	int i, n;
	double root;
	double *a, *b;

public:
	void synthetic_division();
	~synthetic()
	{
		delete[] a, b;
	}
};

void main()
{
	synthetic division;
	division.synthetic_division();
}

void synthetic::synthetic_division()
{
	cout << "\n输入多项式的阶数：";
	cin >> n;
	a = new double[n+1];
	b = new double[n];
	cout << "\n输入原多项式系数：a0 + a1 * x + a2 * x^2 + ..." << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "\n输入a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "\n输入根的值：";
	cin >> root;
	b[n-1] = a[n];
	for (i = (n - 2); i >= 0; i--)
	{
		b[i] = a[i+1] + b[i+1] * root;
	}
	cout << "\n降阶多项式的系数是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nb[" << i << "] = " << b[i] << endl;
	}
}