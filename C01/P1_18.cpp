// P1_18.cpp
// 用指针符号处理一维数组的示范程序

#include <iostream>

using namespace std;

class program18
{
    private:
        int i;
        double b[3];

    public:
        void array();
};

// 主函数
int main()
{
    program18 p18;
    p18.array();
}

// 数值函数
void program18::array()
{
    b[0] = 0.5; b[1] = 1.5; b[2] = -2.5;
    cout << "\n向量的元素是: " << endl;
    for (i = 0; i < 3; i++)
    { cout << (2 * ( *(b+i) )) << endl; }
}
