#include<iostream>
#include<vector>
using namespace std;
//动态规划，状态转移：顺序访问，比较之前收益的最大值和当前值减去之前的最小值，选取大的作为到当前位置的收益，更新最小值。
int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0)
        return 0;
    int max = 0;
    int min = prices[0];
    for(int i = 1;i<prices.size();i++)
    {
        if(prices[i] - min > max)
        {
            max = prices[i] - min;
        }
        if (prices[i] < min)
            min = prices[i]; 

    }
    return max;
}

int main()
{
    int a[] = {7,6,4,3,1};
    vector<int> data(a, a+6);
    int res = maxProfit(data);
    cout<<res<<endl;
    system("pause");
    return 0;
}