//���Իع�
#include <iostream>
#include <math.h>
#include <fstream>
#include <process.h>

using namespace std;

class regression
{
private:
	int i, n;
	double a, b, sum_x, sum_y, sum_xsq, sum_xy, rsq, rsq_num, rsq_denom;
	double *y_model, *x, *y;

public:
	regression()
	{
		sum_x = 0.0;
		sum_y = 0.0;
		sum_xsq = 0.0;
		sum_xy = 0.0;
		rsq_num = 0.0;
		rsq_denom = 0.0;
	}
	void regression_input();
	void sline();
	void exp1();
	void exp2();
	void exp3();
	void power();
	void logarithmic();
	void square_root();
	void one_third();
	void inverse();
	void summations();
	void r_sq();
	~regression()
	{
		delete[] x, y, y_model;
	}
};

void main()
{
	int choice;
	cout << "\n�������з�����ϣ�" << endl;
	cout << "\n1. ֱ�ߣ�Y = A * X + B" << endl;
	cout << "\n2. ָ��1��Y = A * (B ^ X)" << endl;
	cout << "\n3. ָ��2��Y = A * EXP(B * X)" << endl;
	cout << "\n4. ָ��3��Y = A * EXP(X) + B" << endl;
	cout << "\n5. �ݺ�����Y = A * (X ^ B)" << endl;
	cout << "\n6. ����������Y = A * LN(X) + B" << endl;
	cout << "\n7. ƽ����������Y = A * SQRT(X) + B" << endl;
	cout << "\n8. 1/3���ݺ�����Y = A * (X ^ 0.33) + B" << endl;
	cout << "\n9. ���Ⱥ�����Y = A / X + B" << endl;
	cout << "\n�������ѡ��1 - 9��";
	cin >> choice;
	regression curvefit;
	curvefit.regression_input();
	if (choice == 1) {curvefit.sline();}
	if (choice == 2) {curvefit.exp1();}
	if (choice == 3) {curvefit.exp2();}
	if (choice == 4) {curvefit.exp3();}
	if (choice == 5) {curvefit.power();}
	if (choice == 6) {curvefit.logarithmic();}
	if (choice == 7) {curvefit.square_root();}
	if (choice == 8) {curvefit.one_third();}
	if (choice == 9) {curvefit.inverse();}
}

void regression::regression_input()
{
	ifstream fin("regression.dat");
	fin >> n;
	x = new double[n];
	y = new double[n];
	y_model = new double[n];
	for (i = 0; i < n; i++)
	{
		fin >> x[i] >> y[i];
	}
	fin.close();
}

void regression::sline()
{
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n���ֱ�ߣ�Y = A * X + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i ++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::exp1()
{
	for (i = 0; i < n; i++)
	{
		if (y[i] <= 0.0)
		{
			cout << "\n���������ָ��������ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		y[i] = log(y[i]);
	}
	summations();
	b = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	a = (sum_y - b * sum_x) / n;
	a = exp(a);
	b = exp(b);
	cout << "\n���ָ������1��Y  = A * (B ^ X)" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = log(b) * x[i] + log(a);
	}
	r_sq();
}

void regression::exp2()
{
	for (i = 0; i < n; i++)
	{
		if (y[i] <= 0.0)
		{
			cout << "\n���������ָ��������ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		y[i] = log(y[i]);
	}
	summations();
	b = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	a = (sum_y - b * sum_x) / n;
	a = exp(a);
	cout << "\n���ָ������2��Y  = A * EXP(B * X)" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = b * x[i] + log(a);
	}
	r_sq();
}

void regression::exp3()
{
	for (i = 0; i < n; i++)
	{
		x[i] = exp(x[i]);
	}
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n���ָ������3��Y  = A * EXP(X) + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::power()
{
	for (i = 0; i < n; i++)
	{
		if ((y[i] <= 0.0) || (x[i] <= 0.0))
		{
			cout << "\n����������ݺ�����ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		y[i] = log(y[i]);
		x[i] = log(x[i]);
	}
	summations();
	b = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	a = (sum_y - b * sum_x) / n;
	a = exp(a);
	cout << "\n����ݺ�����Y = A * (X ^ B)" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = b * x[i] + log(a);
	}
	r_sq();
}

void regression::logarithmic()
{
	for (i = 0; i < n; i++)
	{
		if (x[i] <= 0.0)
		{
			cout << "\n��������϶���������ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		x[i] = log(x[i]);
	}
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n��϶���������Y = A * LN(X) + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::square_root()
{
	for (i = 0; i < n; i++)
	{
		if (x[i] < 0.0)
		{
			cout << "\n���������ƽ����������ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		x[i] = sqrt(x[i]);
	}
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n���ƽ����������Y = A * SQRT(X) + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::one_third()
{
	for (i = 0; i < n; i++)
	{
		if (x[i] < 0.0)
		{
			cout << "\n���������1/3���ݺ�����ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		x[i] = pow(x[i], 0.33);
	}
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n���1/3���ݺ�����Y = A * (X ^ 0.33) + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::inverse()
{
	for (i = 0; i < n; i++)
	{
		if (x[i] == 0.0)
		{
			cout << "\n��������Ϸ��Ⱥ�����ʧ��..." << endl;
			exit(0);
		}
	}
	for (i = 0; i < n; i++)
	{
		x[i] = 1.0 / x[i];
	}
	summations();
	a = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
	b = (sum_y - a * sum_x) / n;
	cout << "\n��Ϸ��Ⱥ�����Y = A / X + B" << endl;
	cout << "\nA = " << a << " B = " << b;
	for (i = 0; i < n; i++)
	{
		y_model[i] = a * x[i] + b;
	}
	r_sq();
}

void regression::summations()
{
	for (i = 0; i < n; i++)
	{
		sum_x += x[i];
		sum_y += y[i];
		sum_xsq += pow(x[i], 2);
		sum_xy += x[i] * y[i];
	}
}

void regression::r_sq()
{
	for (i = 0; i < n; i++)
	{
		rsq_num += pow((y_model[i] - sum_y / n), 2);
		rsq_denom += pow((y[i] - sum_y / n), 2);
	}
	rsq = rsq_num / rsq_denom;
	cout << "\nr^2 = " << rsq << endl;
}