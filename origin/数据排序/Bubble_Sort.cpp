//��ð�����������Ԫ�ؽ�������

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

//������
void bsort::sorting()
{
	cout << "\n����Ԫ�ظ�����";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n����x[" << i << "] = ";
		cin >> x[i];
	}
	bubblesort(x, n);
	cout << "\n����õ������ǣ�" << endl;
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