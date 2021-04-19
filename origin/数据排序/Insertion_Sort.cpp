//用插入排序法对数组元素进行排序
#include <iostream>

using namespace std;

class isort
{
private:
	int i, j, n;
	double temp;
	double *x;

public:
	void insertion_sort(double *, int);
	void sorting();
	~isort()
	{
		delete[] x;
	}
};

void main()
{
	isort sort;
	sort.sorting();
}

//排序函数
void isort::sorting()
{
	cout << "\n输入元素个数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	insertion_sort(x, n);
	cout << "\n排序好的数组是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}

void isort::insertion_sort(double *x, int m)
{
	for (i = 1; i < m; i++)
	{
		temp = x[i];
		j = i;
		while((j > 0) && (x[j-1] > temp))
		{
			x[j] = x[j-1];
			j--;
		}
		x[j] = temp;
	}
}