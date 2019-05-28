// P1_11.cpp

#include <iostream>
#include <cmath>

using namespace std;

class program11
{
    private:
        int choice;
        double a, result;

    public:
        void switch_case_example()
        {
            a = 4;
            cout << "\n计算" << a << "的平方根, 输入1" << endl;
            cout << "\n计算" << a << "的对数, 输入2" << endl;
            cout << "\n计算" << a << "的指数, 输入3" << endl;
            cout << "\n输入你的选择(1, 2或3) ";
            cin >> choice;
            switch (choice)
            {
                case 1:
                    result = sqrt(a);
                    cout << "\n平方根 = " << result << endl;
                    break;
                case 2:
                    result = log(a);
                    cout << "\n对数 = " << result << endl;
                    break;
                case 3:
                    result = exp(a);
                    cout << "\n指数 = " << result << endl;
                    break;
                default:
                    cout << "\n你输入了错误的选择," << choice << endl;
            }
        }
};

// 主函数
int main()
{
    program11 p11;
    p11.switch_case_example();
    return 0;
}


