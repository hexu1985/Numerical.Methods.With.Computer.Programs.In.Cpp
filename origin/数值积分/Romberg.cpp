//RombergÇó»ý·¨
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class romberg
{
private:
	int i, j, imax, jmax;
	double f, h, a, b, term1, term2, **I;

public:
	double func(double x)
	{
		f = exp(-x * x);
		return f;
	}
	void integral();
	~romberg()
	{
		for (i = 0; i < imax; i++)
		{
			delete[] I[i];
		}
		delete[] I;
	}
};

void main()
{
	romberg integration;
	integration.integral();
}

void romberg::integral()
{
	imax = 5;
	jmax = 5;
	I = new double*[imax];
	for (i = 0; i < imax; i++)
	{
		I[i] = new double[jmax];
	}
	a = 0;
	b = 2;
	h = b - a;
	ofstream fout("romberg.txt");
	I[0][0] = (func(a) + func(b)) * h / 2;
	fout << I[0][0] << endl;
	for (i = 1; i < imax; i++)
	{
		I[i][0] = 0.0;
		term1 = h / pow(2.0, i);
		term2 = pow(2.0, i) - 1;
		for (j = 1; j <= term2; j += 2)
		{
			I[i][0] += func(a + j * term1);
		}
		I[i][0] = 0.5 * I[i-1][0] + term1 * I[i][0];
		fout << I[i][0] << endl;
	}
	for (j = 1; j < jmax; j++)
	{
		for (i = 0; i < (imax - j); i++)
		{
			I[i][j] = (pow(4.0, j) * I[i+1][j-1] - I[i][j-1]) / (pow(4.0, j) - 1);
			fout << I[i][j] << endl;
		}
	}
	fout.close();
}