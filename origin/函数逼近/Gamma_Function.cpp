//计算Gamma函数值
#include <iostream>

using namespace std;

class gamma
{
private:
	int i, n;
	double F, prod, result, x, y;
	double a[25];

public:
	double gamma_fn(double);
	void solution();
};

void main()
{
	gamma gamma0;
	gamma0.solution();
}

void gamma::solution()
{
	cout << "\n输入x（x > 0） = ";
	cin >> x;
	y = x;
	if (x > 2)
	{
		prod = 1.0;
		do
		{
			x--;
			prod *= x;
		}while (x > 2);
		result = prod * gamma_fn(x);
	}
	else
	{
		result = gamma_fn(x);
	}
	cout << "\n在" << y << "点的Gamma函数值 = " << result << endl;
}

double gamma::gamma_fn(double y)
{
	n = 24;
	a[0] = 1.0;
	a[1] = 0.5772156649015329;
	a[2] = -0.6558780715202538;
	a[3] = -0.0420026350340952;
	a[4] = 0.1665386113822915;
	a[5] = -0.0421977345555443;
	a[6] = -0.009621971527877;
	a[7] = 0.007218943246663;
	a[8] = -0.0011651675918591;
	a[9] = -0.0002152416741149;
	a[10] = 0.0001280502823882;
	a[11] = -0.0000201348547807;
	a[12] = -0.0000012504934821;
	a[13] = 0.000001133027232;
	a[14] = -0.0000002056338417;
	a[15] = 0.000000006116095;
	a[16] = 0.0000000050020075;
	a[17] = -0.0000000011812746;
	a[18] = 0.0000000001043427;
	a[19] = 0.0000000000077823;
	a[20] = -0.0000000000036968;
	a[21] = 0.00000000000051;
	a[22] = -0.0000000000000206;
	a[23] = -0.0000000000000054;
	a[24] = 0.0000000000000014;
	F = a[n];
	for (i = (n - 1); i >= 0; i--)
	{
		F = F * y + a[i];
	}
	F *= y;
	return(1 / F);
}