// P1_6.cpp

#include <iostream>

using namespace std;

class program6
{
    private:
        int i;
        double sum;

    public:
        void sum_series()
        {
            sum = 0;
            for (i = 1; i <= 100; i++)
            { sum += i*i; }
            cout << "\nsum = " << sum << endl;
        }
};

// 主函数
int main()
{
    program6 p6;
    p6.sum_series();

    return 0;
}
