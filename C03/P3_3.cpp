// P3_3.cpp
// 具有列选主元和从前到后代入的LU分解
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class lu
{
private:
    int i, j, k, n, *pivrow;
    double eps, pivot, sum, a1, a2, *b, **a;

public:
    void lu_input();            // 数据输入的函数声明
    void lu_decomposition();    // 分解与代入函数声明
    void lu_output();           // 结果输出的函数声明
    ~lu()                       // 释放存储器
    {
        delete[] b;
        delete[] pivrow;
        for (i = 0; i < n; i++)
        {
            delete[] a[i];
        }
        delete[] a;
    }
};                                  // 类lu结束

int main()
{
    lu solution;
    solution.lu_input();            // 输入系数矩阵
    solution.lu_decomposition();    // 执行LU分解, 从前到后代入
    solution.lu_output();           // 输出结果
}

void lu::lu_input()
{
//    cout << "\n输入方程的个数: ";
    cout << "输入方程的个数: ";
    cin >> n;                       // 输入方程个数
    b = new double[n];              // 动态分配存储器
    pivrow = new int[n];
    a = new double*[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }
    for (i = 0; i < n; i++)         // 输入系数矩阵的各元素
        for (j = 0; j < n; j++)
        {
            cout << "\n输入a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    for (i = 0; i < n; i++)         // 输入右端向量的各元素
    {
        cout << "\n输入b[" << i << "] = ";
        cin >> b[i];
    }
    cout << "\n输入最小主元素：";
    cin >> eps;
}                                   // 输入段结束

void lu::lu_decomposition()         // LU分解与从前到后代入函数
{
    for (j = 0; j < n; j++)         // LU分解
    {
        if (j > 0)                  // 计算上三角矩阵U
        {
            for (i = 0; i < j; i++)
            {
                if (i > 0)
                {
                    sum = 0.0;
                    for (k = 0; k <= (i-1); k++)
                    {
                        sum += a[i][k]*a[k][j];
                    }
                }
                else
                {
                    sum = 0.0;
                }
                a[i][j] = a[i][j] - sum;
            }
        }
        pivot = 0.0;
        for (i = j; i < n; i++)     // 计算下三角矩阵L
        {
            if (j > 0)
            {
                sum = 0.0;
                for (k = 0; k <= (j-1); k++)
                {
                    sum += a[i][k] * a[k][j];
                }
            }
            else
            {
                sum = 0.0;
            }
            a[i][j] = a[i][j] - sum;
            if (fabs(a[i][j]) > pivot)
            {
                pivrow[j] = i;
                pivot = fabs(a[i][j]);
            }
        }
        if (pivot < eps)
        {
            cout << "\n矩阵可能奇异，失败..." << endl;
            exit(0);
        }
        if (pivrow[j] != j)         // 列选主元
        {
            for (k = 0; k < n; k++)
            {
                a1 = a[pivrow[j]][k];
                a[pivrow[j]][k] = a[j][k];
                a[j][k] = a1;
            }
        }
        if (j != (n-1))             // 计算下三角矩阵L
        {
            for (i = (j+1); i < n; i++)
            {
                a[i][j] /= a[j][j];
            }
        }
    }
    for (i = 0; i < n; i++)         // 从前到后代入，先计算LY = B
    {
        sum = b[pivrow[i]];
        b[pivrow[i]] = b[i];
        if (i > 0)
        {
            for (j = 0; j < (i-1); j++)
            {
                sum -= a[i][j]*b[j];
            }
        }
        b[i] = sum;
    }
    for (i = (n-1); i >= 0; i--)    // 再计算UX = Y
    {
        sum = b[i];
        if (i < (n-1))
        {
            for (j = (i+1); j < n; j++)
            {
                sum -= a[i][j]*b[j];
            }
        }
        b[i] = sum / a[i][i];
    }
}

void lu::lu_output()
{
    cout << "\n结果是：" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "\nx[" << i << "] = " << b[i] << endl;
    }
}
