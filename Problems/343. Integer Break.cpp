#include <iostream>
#include <vector>
#include<cmath>

using namespace std;
/*最佳解决思路为将其拆分为n个3相乘再加上一个大于3小于6的数*/
int integerBreak(int n)
{

    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int num_3 = (int)n / 3;
    int remainder = n % 3;
    if (remainder == 1)
    {
        remainder = 4;
        num_3--;
    }
    else if (remainder == 0)
        remainder = 1;

    return (int)pow(3, num_3) * remainder;
}
int raw_integerBreak(int n)
{
    if (n < 2)
        return 0;
    vector<int> res;
    res.resize(n + 1);
    res[0] = 0;
    res[1] = 0;
    res[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        res[i] = 0;
        for (int j = 1; j < i; j++)
        {
            res[i] = max(max(res[i], res[j] * (i - j)), j * (i - j));
        }
    }
    return res[n];
}

int main()
{
    int n = 10;
    int res = integerBreak(n);
    cout << res << endl;
    return 0;
}