// P1_3.cpp
// 整型和浮点型数据的使用说明程序

#include <iostream>
#include <cmath>

using namespace std;

class program3
{
    private:
        int a, b;
        long int c;
        double x, y;

    public:
        void output()
        {
            a = 2;
            b = 78;
            c = 213457;
            long int d = a * b + c;
            cout << "d = " << d << endl;
            x = 1.67e5;
            y = log(x);
            cout << "y = " << y << endl;
        }
};

// 主函数
int main()
{
    program3 p3;
    p3.output();

    return 0;
}

