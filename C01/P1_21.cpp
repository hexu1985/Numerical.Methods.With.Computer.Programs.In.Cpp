// P1_21.cpp
// 构造函数的使用

#include <iostream>

using namespace std;

class program21
{
    private:
        int i;
        int sum;

    public:
        program21()     // 构造函数
        { sum = 0; }

        void summation()
        {
            for (i = 0; i < 10; i++)
            { sum += i; }
            cout << "\nSum = " << sum << endl;
        }
};

// 主函数
int main()
{
    program21 p21;
    p21.summation();

    return 0;
}
