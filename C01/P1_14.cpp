// P1_14.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program14
{
    private:
        double result;

    public:
        void mult_calc(double, double &, double &);
};

// 主函数
int main()
{
    double x, y, z;
    cout << "\n输入一个数(大于0) ";
    cin >> x;
    program14 p14;
    p14.mult_calc(x, y, z);
    cout << "\n" << x << "的平方根是" << y << endl;
    cout << "\n" << x << "的倒数是" << z << endl;

    return 0;
}

// 函数定义
void program14::mult_calc(double a, double &b, double &c)
{
    b = sqrt(a);
    c = 1/a;
}
