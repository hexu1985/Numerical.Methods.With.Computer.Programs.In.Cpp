// P2_3.cpp

#include <iostream>
#include <cmath>

using namespace std;

class P2_3
{
    private:
        int i;
        float x, sum, mult;

    public:
        void series()
        {
            i = 1;
            sum = mult = 1;
            cout << "\n输入x: ";
            cin >> x;
            do
            {
                mult *= x/i;
                sum += mult;
                i++;
            } while (fabs(mult) > 1e-15);
            cout << "\n exp(x)的值是" << sum << endl;
            cout << "\n 准确值是" << exp(x) << endl;
        }
};

// 主函数
int main()
{
    P2_3 P3;
    P3.series();

    return 0;
}
