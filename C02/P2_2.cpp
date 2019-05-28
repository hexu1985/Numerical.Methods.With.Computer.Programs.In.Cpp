// P2_2.cpp

#include <iostream>
#include <cmath>

using namespace std;

class P2_2
{
    private:
        double x, expx;

    public:
        void expo()
        {
            cout << "\n输入 ";
            cin >> x;
            cout.setf(ios::fixed, ios::floatfield);
            cout.precision(8);
            expx = 1 + x;
            cout << "\n截取前两项给出 " << expx << endl;
            expx = 1 + x + x*x/2 + x*x*x/6;
            cout << "\n截取前四项给出 " << expx << endl;
            expx = (1 + 2*x/3 + x*x/6)/(1 - x/3);
            cout << "\n帕德逼近式给出 " << expx << endl;
            expx = exp(x);
            cout << "\n C++库函数给出 " << expx << endl;
        }
};

// 主函数
int main()
{
    P2_2 P2;
    P2.expo();

    return 0;
}

