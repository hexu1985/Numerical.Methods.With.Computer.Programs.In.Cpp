//用快速排序法对数组元素进行排序
#include <iostream>

using namespace std;

class qusort
{
private:
	int i, n, l_h, pivot_loc, r_h;
	double pivot;
	double *x;

public:
	void quicksort(double *, int, int);
	void sorting();
	~qusort()
	{
		delete[] x;
	}
};

void main()
{
	qusort sort;
	sort.sorting();
}

//排序函数
void qusort::sorting()
{
	cout << "\n输入元素个数：";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n输入x[" << i << "] = ";
		cin >> x[i];
	}
	quicksort(x, 0, (n-1));
	cout << "\n排序好的数组是：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nx[" << i << "] = " << x[i] << endl;
	}
}

//快速算法排序函数
void qusort::quicksort(double *x, int left, int right)
{
	l_h = left;
	r_h = right;
	pivot = x[left];
	while (left < right)
	{
		while ((x[right] >= pivot) && (left < right))
		{
			right--;
		}
		if (left != right)
		{
			x[left] = x[right];
			left++;
		}
		while ((x[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left != right)
		{
			x[right] = x[left];
			right--;
		}
	}
	x[left] = pivot;
	pivot_loc = left;
	left = l_h;
	right = r_h;
	if (left < pivot_loc)
	{
		quicksort(x, left, (pivot_loc - 1));
	}
	if (right > pivot_loc)
	{
		quicksort(x, (pivot_loc + 1), right);
	}
}