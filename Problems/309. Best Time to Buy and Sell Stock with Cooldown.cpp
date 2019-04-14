#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0)
        return 0;
    vector<int> buy(prices.size());
    vector<int> sell(prices.size());
    buy[0] = -prices[0];
    int ret=0;
    for(int i = 1;i<prices.size();i++)
    {
        sell[i] = max(buy[i-1] + prices[i], sell[i-1] - prices[i-1] + prices[i]);
        ret = max(ret, sell[i]);
        if(i == 1)
            buy[i] = -prices[i];
        else{
            buy[i] = max(sell[i-2] - prices[i], buy[i-1] + prices[i-1] - prices[i]);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,0,2};
    vector<int> prices(a,a+5);
    int res = maxProfit(prices);
    cout<<res<<endl;
    return 0;
}
