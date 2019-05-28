// P3_1.cpp
// Gauss消去法程序

#include <iostream>
#include <cmath>

using namespace std;

class gauss
{
    private:
        int i, j, k, n;
        double eps, ratio, sum, *x, **a;

    public:
        void gauss_input();         // 数据输入的函数声明
        void gauss_elimination();   // 消去法的函数声明
        void gauss_output();        // 结果输出的函数声明
        ~gauss()                    // 释放存储器
        {
            delete [] x;
            for (i=0; i<n; i++) { delete [] a[i]; }
            delete [] a;
        }
};                                  // 类gauss结束

int main()                         // 主函数
{
    gauss solution;
    solution.gauss_input();         // 输入增广矩阵的系数
    solution.gauss_elimination();   // 执行Gauss消去法
    solution.gauss_output();        // 输出结果
    return 0;
}

void gauss::gauss_input()           // 数据输入函数
{
    cout << "输入方程的个数:";      // 输入方程个数
    cin >> n;
    x = new double[n];              // 动态分配存储器
    a = new double *[n];
    for (i=0; i<n; i++) { a[i] = new double [n+1]; }
    for (i=0; i<n; i++)             // 输入系数矩阵的各元素
        for (j=0; j<n; j++)
        {
            cout << "\n输入a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    for (i=0; i<n; i++)             // 输入右端向量的各元素
    {
        cout << "\n输入b[" << i << "] = ";
        cin >> a[i][n];
    }
    cout << "\n输入最小主元素";
    cin >> eps;
}                                   // 输入段结束

void gauss::gauss_elimination()     // Gauss消去法函数
{
    for (k=0; k<(n-1); k++)
    {
        for (i=(k+1); i<n; i++)
        {
            if (fabs(a[k][k]) < eps)
            {
                cout << "\n主元素太小. 失败..." << endl;
                exit(0);
            }
            ratio = a[i][k]/a[k][k];
            for (j=(k+1); j<(n+1); j++)
            { a[i][j] -= ratio * a[k][j]; }
            a[i][k] = 0;
        }
    }
    x[n-1] = a[n-1][n]/a[n-1][n-1]; // 回代
    for (i=(n-2); i>=0; i--)
    {
        sum = 0.0;
        for (j=(i+1); j<n; j++)
        { sum += a[i][j] * x[j]; }
        x[i] = (a[i][n]-sum)/a[i][i];
    }
}

void gauss::gauss_output()
{
    cout << "\n结果是: " << endl;
    for (i=0; i<n; i++)
    { cout << "\nx[" << i << "] = " << x[i] << endl; }
}
