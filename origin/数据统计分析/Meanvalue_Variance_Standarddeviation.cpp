//计算数据的平均值、方差和标准差
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
	cout << "\n输入观测次数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	for (i = 0; i < n; i++)
	{
		xbar += x[i];
	}
	xbar /= n;
	cout << "\n平均值 = " << xbar << endl;
	for (i = 0; i < n; i++)
	{
		var += (x[i] - xbar)*(x[i] - xbar);
	}
	var /= (n-1);
	cout << "\n方差 = " << var << endl;
	std_dev = sqrt(var);
	cout << "\n标准差是 " << std_dev << endl;
}