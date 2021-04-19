//用冒泡排序对数组元素进行排序

#include <iostream>

using namespace std;

class bsort
{
private:
	int i, j, n, flag;
	double temp;
	double *x;

public:
	void bubblesort(double *, int);
	void sorting();
	~bsort()
	{
		delete[] x;
	}
};

void main()
{
	bsort sort;
	sort.sorting();
}

//排序函数
void bsort::sorting()
{
	cout << "\n输入元素个数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	bubblesort(x, n);
	cout << "\n排序好的数组是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}

void bsort::bubblesort(double *y, int m)
{
	for (i = (m-1); i > 0; i--)
	{
		flag = 0;
		for (j = 1; j <= i; j++)
		{
			if (y[j-1] > y[j])
			{
				temp = y[j-1];
				y[j-1] = y[j];
				y[j] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}