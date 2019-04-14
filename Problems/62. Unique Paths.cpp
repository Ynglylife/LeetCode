#include<iostream>
#include<vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int> > res;
    res.resize(m);
    for(int i = 0;i<res.size();i++)
        res[i].resize(n);
    for(int i = 0;i<res[0].size();i++)
        res[0][i] =1;
    for(int i =0;i<res.size();i++)
        res[i][0] = 1;
    for(int i =1;i<res.size();i++)
    {
        for(int j =1; j<res[i].size();j++)
        {
            res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }
    return res[m-1][n-1];
}

int main()
{
    int m = 3;
    int n = 2;
    int res = uniquePaths(m,n);
    cout<<res<<endl;
    system("pause");
    return 0;
}