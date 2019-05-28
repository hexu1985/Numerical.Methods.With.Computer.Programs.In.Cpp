// P1_2.cpp

#include <iostream>

using namespace std;

class program2
{
    private:
        char a, b;

    public:
        void output()
        {
            a=127;
            b='A';
            cout << "a=" << a << endl;
            cout << "b=" << b << endl;
        }
};

// 主函数
int main()
{
    program2 p2;
    p2.output();
}
