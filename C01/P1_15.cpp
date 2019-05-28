// P1_15.cpp
// 处理输入文件的示范程序

#include <iostream>
#include <fstream>

using namespace std;

class program15
{
    private:
        int n;
        double a, b, c;

    public:
        void input();
};

// 主函数
int main()
{
    program15 p15;
    p15.input();

    return 0;
}

// input函数
void program15::input()
{
    ifstream fin("p15.dat");
    fin >> n;
    fin >> a >> b >> c;
    fin.close();
    cout << "\nn=" << n << endl;
    cout << "\na/2=" << (a/2) << endl;
    cout << "\nb/3=" << (b/3) << endl;
    cout << "\nc/4=" << (c/4) << endl;
}
