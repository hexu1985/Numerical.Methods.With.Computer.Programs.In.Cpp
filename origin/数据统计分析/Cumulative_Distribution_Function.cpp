//����һ�����ݵ��ۻ��ֲ�
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
	cout << "\n����۲������";
	cin >> n;
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		cout << "\n����x[" << i << "] = ";
		cin >> x[i];
	}
	//����qsort��Ҫ�ıȽϺ�����
	int doublecmp(const void *v1, const void *v2);

	//Ϊ�˶��������򣬵���C++�⺯��qsort����stdlib.h�ж���ģ�
	qsort(x, n, sizeof(double), doublecmp);
	cout << "\n�������������";
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

//�û�����Ķ���qsort�ıȽϺ���
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

