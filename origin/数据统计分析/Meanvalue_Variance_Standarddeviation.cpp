//�������ݵ�ƽ��ֵ������ͱ�׼��
#include <iostream>
#include <math.h>

using namespace std;

class MeanVar
{
private:
	int i, n;
	double xbar, var, std_dev;
	double *x;

public:
	MeanVar()
	{
		xbar = var = 0.0;
	}
	void mean_var();
	~MeanVar()
	{
		delete[] x;
	}
};

void main()
{
	MeanVar moments;
	moments.mean_var();
}

void MeanVar::mean_var()
{
	cout << "\n����۲������";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n����x[" << i << "] = ";
		cin >> x[i];
	}
	for (i = 0; i < n; i++)
	{
		xbar += x[i];
	}
	xbar /= n;
	cout << "\nƽ��ֵ = " << xbar << endl;
	for (i = 0; i < n; i++)
	{
		var += (x[i] - xbar)*(x[i] - xbar);
	}
	var /= (n-1);
	cout << "\n���� = " << var << endl;
	std_dev = sqrt(var);
	cout << "\n��׼���� " << std_dev << endl;
}