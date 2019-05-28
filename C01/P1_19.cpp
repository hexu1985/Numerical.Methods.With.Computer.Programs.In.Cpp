// P1_19.cpp
// 说明指针概念的程序

#include <iostream>

using namespace std;

class program19
{
    private:
        double y, value;
        double *x;

    public:
        void pointer();
};

// 主函数
int main()
{
    program19 p19;
    p19.pointer();

    return 0;
}


// 解释使用指针的函数
void program19::pointer()
{
    y = 13.7;
    x = &y;     // 指针x指向y
    value = *x;
    cout << "\ny的地址是" << x << endl;
    cout << "\ny的值是" << value << endl;
}
