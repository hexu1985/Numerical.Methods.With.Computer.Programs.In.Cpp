// P1_1.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program1
{
    private:
        double a, result;

    public:
        void square_root()
        {
            cout << "\n输入一个数 ";
            cin >> a;
            result = sqrt(a);
            cout << "\n数的平方根是 " << result << endl;
        }
};

// 主函数
int main()
{
    program1 p1;
    p1.square_root();

    return 0;
}
