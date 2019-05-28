// P1_17.cpp
// 处理方阵示范程序

#include <iostream>

using namespace std;

class program17
{
    private:
        int i, j;
        double a[3][3];

    public:
        void matrix();
};

// 主函数
int main()
{
    program17 p17;
    p17.matrix();

    return 0;
}

// 存储和输出矩阵元素的程序
void program17::matrix()
{
    a[0][0] = 0.5;  a[0][1] = 0.5;  a[0][2] = -0.5;
    a[1][0] = 0.5;  a[1][1] = 1;    a[1][2] = -1;
    a[2][0] = -1;   a[2][1] = 0.5;  a[2][2] = 0.5;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        { cout << "\na[" << i << "][" << j << "] = " << a[i][j] << endl; }
}

