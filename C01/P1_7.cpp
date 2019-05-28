// P1_7.cpp
// 'while'循环使用说明的程序

#include <iostream>
#include <cstdio>

using namespace std;

class program7
{
    private:
        char choice;

    public:
        void menu()
        {
            choice = 'a';
            while (choice != 'T')
            {
                cout << "输入'T'并按Return键结束..." << endl;
                choice = fgetc(stdin);
            }
        }
};

// 主函数
int main()
{
    program7 p7;
    p7.menu();
    return 0;
}
