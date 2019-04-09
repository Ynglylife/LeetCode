#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


// dp[i][j]表示i到j堆石子，先手比后手多出的石子个数，则dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
//表示当前状态先手要么取i堆，要么取j堆，对应前一个状态，也就是另一个人作为先手时对应分别为dp[i+1][j]和dp[i][j-1]
bool stoneGame(vector<int>& piles)
{
    vector< vector<int> > res;
    res.resize(piles.size());
    for(int i = 0;i<res.size();i++)
        res[i].resize(piles.size());
    for(int i = 0;i<piles.size();i++)
        res[i][i] = piles[i];
    for(int l = 1; l < piles.size(); l++)
    {
        for(int i = 0; i + l<piles.size(); i++)
        {
            res[i][i+l] = max(piles[i] - res[i+1][i+l], piles[i+l] - res[i][i+l-1]);
        }
    }
    return res[0][piles.size() -1] > 0;
}

int main()
{
    int a[] = {5,3,4,5};
    vector<int> data(a,a+4);
    bool res = stoneGame(data);
    cout<<res<<endl;
    return 0;
}