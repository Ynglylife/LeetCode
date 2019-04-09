#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int> res;
    res.resize(cost.size());
    res[cost.size()-1] = 0;
    res[cost.size()-2] = min(cost[cost.size() -2], cost[cost.size()-1]);
    for(int i = cost.size()-3;i>=0;i--)
    {
        res[i] = min(cost[i] + res[i+1], cost[i+1] + res[i+2]);
    }
    return res[0];
}

int main()
{
    int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> data(a, a+10);
    int res = minCostClimbingStairs(data);
    cout<<res<<endl;
    system("pause");
    return 0;
}