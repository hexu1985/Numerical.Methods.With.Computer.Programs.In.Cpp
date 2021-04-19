//生成一组数据的累积分布
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class cumulative
{
private:
	int i, j, n, interval;
	double counter, frac, h, upplim;
	double *x;

public:
	void cumul();
	~cumulative()
	{
		delete[] x;
	}
};

void main()
{
	cumulative distribution;
	distribution.cumul();
}

void cumulative::cumul()
{
	cout << "\n输入观测次数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	//声明qsort需要的比较函数的
	int doublecmp(const void *v1, const void *v2);

	//为了对数组排序，调用C++库函数qsort（在stdlib.h中定义的）
	qsort(x, n, sizeof(double), doublecmp);
	cout << "\n输入区间个数：";
	cin >> interval;
	h = (x[n-1] - x[0]) / interval;
	upplim = x[0] + h;
	for (j = 0; j < interval; j++)
	{
		counter = 0;
		for (i = 0; i < n; i++)
		{
			if (x[i] <= upplim)
			{
				counter++;
			}
		}
		frac = counter / n;
		if (j == (interval - 1))
		{
			frac = 1.0;
		}
		cout << upplim << setw(10) << frac << endl;
		upplim += h;
	}
}

//用户定义的对于qsort的比较函数
int doublecmp(const void *v1, const void *v2)
{
	double p = ((*(double *)v1 - *(double *)v2));
	if (p < 0)
		return (-1);
	else if (p == 0)
		return (0);
	else
		return (1);
}

