//������ָ���㴦����ʽ����һ�׵���ֵ
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
	cout << "\n�������ʽ�Ľ�����";
	cin >> n;
	a = new double[n+1];
	cout << "\n�������ʽϵ����a0 + a1 * x + a2 * x^2 + ..." << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "\n����a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "\n����������ʽ�����ڵ㣺";
	cin >> x;
	F = a[n];
	for (i = (n - 1); i >= 0; i--)
	{
		deriv = deriv * x + F;
		F = F * x + a[i];
	}
	cout << "\n����ʽ��" << x << "�㴦��ֵ = " << F << endl;
	cout << "\n����ʽ��" << x << "�㴦�ĵ���ֵ = " << deriv << endl;
}