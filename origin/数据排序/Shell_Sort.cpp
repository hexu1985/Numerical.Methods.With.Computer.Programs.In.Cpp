//用Shell排序法对数组元素进行排序
#include <iostream>

using namespace std;

class ssort
{
private:
	int h, i, j, n;
	double temp;
	double *x;

public:
	void shell_sort(double *, int);
	void sorting();
	~ssort()
	{
		delete[] x;
	}
};

void main()
{
	ssort sort;
	sort.sorting();
}

//排序函数
void ssort::sorting()
{
	cout << "\n输入元素个数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	shell_sort(x, n);
	cout << "\n排序好的数组是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}

void ssort::shell_sort(double *x, int m)
{
	h = 3;
	while (h > 0)
	{
		for (i = h; i < m; i++)
		{
			temp = x[i];
			j = i;
			while ((j >= h) && (x[j-h] > temp))
			{
				x[j] = x[j-h];
				j -= h;
			}
			x[j] = temp;
		}
		if ((h/2) != 0)
		{
			h /= 2;
		}
		else if (h == 1)
		{
			h = 0;
		}
		else
		{
			h = 1;
		}
	}
}