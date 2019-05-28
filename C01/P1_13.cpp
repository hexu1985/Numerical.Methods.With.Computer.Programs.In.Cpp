// P1_13.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program13
{
    private:
        double a, x, f, res;

    public:
        double func(double);
        void result();
};

// 主函数
int main()
{
    program13 p13;
    p13.result();

    return 0;
}

// 函数func的含义
double program13::func(double x)
{
    f = exp(-x*x/2);
    return f;
}

// 函数result的定义
void program13::result()
{
    a = 1.2;
    res = func(a);
    cout << "\n结果是" << res << endl;
}
