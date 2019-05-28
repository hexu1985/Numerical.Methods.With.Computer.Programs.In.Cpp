// P1_9.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program9
{
    private:
        double a, result;

    public:
        void calculation()
        {
            cout << "\n输入一个数";
            cin >> a;
            if (a <= 0)
            {
                cout << "\n不能计算对数." << endl;
            }
            else
            {
                result = log(a);
                cout << "\n" << a << "的对数是" << result << endl;
            }
        }
};

// 主函数
int main()
{
    program9 p9;
    p9.calculation();

    return 0;
}
