// P1_5.cpp

#include <iostream>

using namespace std;

class program5
{
    private:
        int n;

    public:
        void even_odd()
        {
            cout << "\n输入一个整型数 ";
            cin >> n;
            if (n%2 == 0)
            { cout << "\n这是一个偶数." << endl; }
            else
            { cout << "\n这是一个奇数." << endl; }
        }
};

// 主函数

int main()
{
    program5 p5;
    p5.even_odd();

    return 0;
}


