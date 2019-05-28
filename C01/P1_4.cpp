// P1_4.cpp

#include <iostream>
#include <cmath>

using namespace std;

#define PI  3.14159
const double R = 8.314e7;

class program4
{
    private:
        double v, M, T;

    public:
        void av_velocity()
        {
            cout << "\n输入温度(K)和相对分子质量 ";
            cin >> T >> M;
            v = sqrt(8 * R * T / (PI * M));
            cout << "v = " << v << endl;
        }
};

// 主函数
int main()
{
    program4 p4;
    p4.av_velocity();

    return 0;
}
