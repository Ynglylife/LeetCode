#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n)
{
    vector<int> res;
    res.resize(n+1);
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    for(int i = 3;i<=n;i++)
    {
        res[i] = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(res[j] == 0 || res[i-1-j] == 0)
                res[i] = res[i] + res[j] + res[i-1-j];
            else
                res[i] = res[i] + res[j] * res[i-1-j];
        }
    }
    return res[n];
}

int main()
{
    int n = 3;
    int res = numTrees(n);
    cout<<res<<endl;
    return 0;
}