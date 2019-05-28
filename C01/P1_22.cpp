// P1_22.cpp
// 析构函数的使用

#include <iostream>

using namespace std;

class program22
{
    private:
        int i, n;
        double *a;

    public:
        void allocate();

        ~program22()        // 析构函数
        { delete [] a; }
};

// 主函数
int main()
{
    program22 p22;
    p22.allocate();

    return 0;
}

// 动态分配内存函数
void program22::allocate()
{
    cout << "\n输入数组元素个数";
    cin >> n;
    a = new double[n];
    for (i = 0; i < n; i++)
    {
        cout << "\n输入a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "\n你输入了: " << endl;
    for (i = 0; i < n; i++)
    { cout << "\na[" << i << "] = " << a[i] << endl; }
}
