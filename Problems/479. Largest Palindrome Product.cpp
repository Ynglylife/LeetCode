#include<iostream>
#include<cmath>

using namespace std;
//从upper到lower，组合可能的回文数字，然后逐个验证。
int largestPalindrome(int n)
{
    int upper = pow(10,n)-1;
    int lower = upper/10;
    for(int i = upper; i > lower; i--)
    {
        string str_p = to_string(i);
        str_p += string(str_p.rbegin(),str_p.rend());
        long p = stol(str_p);
        for(int j = upper; j > sqrt(p); j--)
        {
            if(p%j==0)
            {
                return p%1337;
            }
        }
    }
    return 9;
}

int main()
{
    int res = largestPalindrome(2);
    cout<<res<<endl;
    system("pause");
    return 0;
}