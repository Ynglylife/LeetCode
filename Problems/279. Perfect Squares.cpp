#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*四平方和定理：每一个整数均可以表示为四个整数的平方和*/
/*如果该数模8余7则一定由4个整数平方和组成*/
/*如果该数减去一个整数平方和余下仍为整数平方和，结果为2*/
/*该数为整数平方和结果为1*/
/*否则为3*/

bool isSquare(int n)
{
    int sqroot = floor(sqrt(n));

    return sqroot * sqroot == n;
}
int numSquares(int n)
{
    if (isSquare(n))
        return 1;

    for (int i = 1; i * i < n; i++)
    {
        if (isSquare(n - i * i))
            return 2;
    }

    int p4 = 1;
    while (n % (4 * p4) == 0)
        p4 *= 4;

    if ((n / p4) % 8 == 7)
        return 4;

    return 3;
}

int main(int argc, char const *argv[])
{
    int n = 1535;
    int res = numSquares(n);
    cout << res << endl;
    return 0;
}
