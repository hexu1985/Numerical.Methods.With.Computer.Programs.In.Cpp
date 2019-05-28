// P1_10.cpp

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class program10
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
                exit(0);
            }
            result = log(a);
            cout << "\n" << a << "的对数是" << result << endl;
        }
};

// 主函数
int main()
{
    program10 p10;
    p10.calculation();

    return 0;
}
