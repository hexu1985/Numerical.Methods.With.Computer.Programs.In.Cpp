// P2_1.cpp
#include <iostream>

using namespace std;

const float a = 1.234;
const float b = 0.0005678;
const double c = 1.234;
const double d = 0.0005678;

class p2_1 
{
    private:
        float x;
        double y;

    public:
        void floating()
        {
            x = a + b;
            y = c + d;
            cout.setf(ios::fixed, ios::floatfield); // 固定格式
            cout.precision(8);                      // 高精度
            cout << x << endl;
            cout << y << endl;
        }
};

// 主函数
int main()
{
    p2_1 p1;
    p1.floating();

    return 0;
}
