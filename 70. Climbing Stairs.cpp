#include<iostream>
#include<vector>

using namespace std;

int climbStairs(int n)
{
    vector<int> res;
    res.resize(n);
    res[0] = 1;
    res[1] = 2;       
    for(int i = 2; i < n; i++)
        res[i] = res[i-1] + res[i-2];
    return res[n-1];
}

int main()
{
    int res = climbStairs(3);
    cout<<res<<endl;
    return 0;
}