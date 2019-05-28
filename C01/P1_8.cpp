// P1_8.cpp
// 'do'循环使用说明的程序

#include <iostream>
#include <cmath>

using namespace std;

class program8
{
    private:
        double x, xnew;
        double difference, ratio, ratio_new, sum;

    public:
        void golden()
        {
            x = 0;
            xnew = 1;
            ratio_new = 0;
            do
            {
                ratio = ratio_new;
                sum = x + xnew;
                x = xnew;
                xnew = sum;
                ratio_new = x/xnew;
                difference = fabs(ratio-ratio_new);
            } while (difference >= 1e-12);
            cout << "\nGolden ratio = " << ratio_new << endl;
        }
};

// 主函数
int main()
{
    program8 p8;
    p8.golden();

    return 0;
}
