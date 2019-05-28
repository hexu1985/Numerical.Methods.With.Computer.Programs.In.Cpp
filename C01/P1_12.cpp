// P1_12.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program12
{
    private:
        double result;

    public:
        void sine(double);
};

// 主函数
int main()
{
    double x;
    cout << "\n输入一个数(用弧度)";
    cin >> x;
    program12 p12;
    p12.sine(x);
    
    return 0;
}

// 函数定义
void program12::sine(double a)
{
    result = sin(a);
    cout << "\nsin(" << a << ") = " << result << endl;
}
