//Lagrange插值法

#include <iostream>
#include <fstream>

using namespace std;

class lagrange
{
private:
	int i, j, n;
	double mult, sum, z;
	double* x, * y;

public:
	void interpolation();
	~lagrange()
	{
		delete[] x, y;
	}
};

void main()
{
	lagrange interp;
	interp.interpolation();
}

void lagrange::interpolation()
{
	ifstream fin ("lagrange.txt");
	fin >> n;
	x = new double[n];
	y = new double[n];
	for (i = 0; i < n; i++)
	{
		fin >> x[i] >> y[i];
	}
	fin.close();
	cout << "\n输入需要插值的点：";
	cin >> z;
	sum = 0.0;
	for (i = 0; i < n; i++)
	{
		mult = 1.0;
		for (j = 0; j < n; j++)
		{
			if (j != i)
			{
				mult *= (z - x[j]) / (x[i] - x[j]);
			}
		}
		sum += mult * y[i];
	}
	cout << "\n插补的值 = " << sum << endl;
}