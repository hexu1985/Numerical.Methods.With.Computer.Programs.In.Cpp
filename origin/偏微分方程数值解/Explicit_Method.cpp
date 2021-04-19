//用显式法求解抛物线型偏微分方程
#include <iostream>
#include <stdio.h>

using namespace std;

class explicit_method
{
private:
	int i, j;
	double y[5][5];

public:
	void exp1()
	{
		y[0][0] = y[1][0] = y[2][0] = y[3][0] = y[4][0] = 25;
		for (j = 1; j < 5; j++)
		{
			y[0][j] = 100;
			y[4][j] = 100;
		}
		for (j = 0; j < 4; j++)
			for (i = 1; i < 4; i++)
			{
				y[i][j+1] = 0.68 * y[i][j] + 0.16 * (y[i+1][j] + y[i-1][j]);
			}
		for (j = 0; j < 5; j++)
			for (i = 0; i < 5; i++)
			{
				cout << "\ny[" << i << "][" << j << "] = " << y[i][j] << endl;
				getchar();
			}
	}
};

void main()
{
	explicit_method pde;
	pde.exp1();
}