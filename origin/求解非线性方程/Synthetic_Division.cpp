//��һ�������֪ʱ���Ͷ���ʽ�׵��ۺϳ���
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
	cout << "\n�������ʽ�Ľ�����";
	cin >> n;
	a = new double[n+1];
	b = new double[n];
	cout << "\n����ԭ����ʽϵ����a0 + a1 * x + a2 * x^2 + ..." << endl;
	for (i = 0; i <= n; i++)
	{
		cout << "\n����a[" << i << "] = ";
		cin >> a[i];
	}
	cout << "\n�������ֵ��";
	cin >> root;
	b[n-1] = a[n];
	for (i = (n - 2); i >= 0; i--)
	{
		b[i] = a[i+1] + b[i+1] * root;
	}
	cout << "\n���׶���ʽ��ϵ���ǣ�" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nb[" << i << "] = " << b[i] << endl;
	}
}