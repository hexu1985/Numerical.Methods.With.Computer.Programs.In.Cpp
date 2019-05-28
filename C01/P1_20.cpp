// P1_20.cpp
// 动态分配内存的程序

#include <iostream>
#include <cstdio>

using namespace std;

class program20
{
    private:
        int i, j, m, n;
        double **a, *b;

    public:
        void dynamic();
};

// 主函数
int main()
{
    program20 p20;
    p20.dynamic();

    return 0;
}

// 动态分配内存的函数
void program20::dynamic()
{
    cout << "\n输入一维数组元素个数 ";
    cin >> m;
    b = new double[m];      // 分配内存
    for (i = 0; i < m; i++)
    {
        cout << "\n输入b[" << i << "] = ";
        cin >> b[i];
    }
    cout << "\n你输入了: " << endl;
    for (i = 0; i < m; i++)
    { cout << "\nb[" << i << "] = " << b[i] << endl; }
    delete [] b;            // 释放内存
    cout << "\n按回车键继续..." << endl;
    getchar();
    cout << "\n输入方阵阶数 ";
    cin >> n;
    a = new double *[n];    // 分配内存
    for (i = 0; i < n; i++) { a[i] = new double [n]; }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "\n输入a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    cout << "\n你输入了: " << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "\na[" << i << "][" << j << "] = " << a[i][j] << endl;
        }
    for (i = 0; i < n; i++) { delete [] a[i]; }
    delete [] a;            // 释放内存
}
