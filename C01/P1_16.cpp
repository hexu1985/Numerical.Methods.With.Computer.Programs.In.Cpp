// P1_16.cpp
// 从输入文件读取和存储结果到输出文件的示范程序

#include <iostream>
#include <fstream>

using namespace std;

class program16
{
    private:
        int n;
        double a, b, c;

    public:
        void store();
};

// 主函数
int main()
{
    program16 p16;
    p16.store();

    return 0;
}

// 输入和输出函数
void program16::store()
{
    ifstream fin("p15.dat");
    fin >> n;
    fin >> a >> b >> c;
    fin.close();
    ofstream fout("p16.out");
    fout << "\nn=" << n << endl;
    fout << "\na/2=" << (a/2) << endl;
    fout << "\nb/3=" << (b/3) << endl;
    fout << "\nc/4=" << (c/4) << endl;
    fout.close();
}
