#include <iostream>
#include <vector>
#include <map>
#include<cmath>
using namespace std;

/*基于递归以及深度优先搜索的方法，使用hash_map记录已经得到的needs对应的最少消费*/
int shoppingOffersWithMap(vector<int> price, vector<vector<int> > special, vector<int> needs, map<vector<int>, int> &hash_map)
{
    if (hash_map.find(needs) != hash_map.end())
    {
        return hash_map[needs];
    }
    int res = 0;
    for (int i = 0; i < price.size(); i++)
        res += price[i] * needs[i];
    for (int i = 0; i < special.size(); i++)
    {  
        int j = 0;
        for( ;j<needs.size();j++)
        {
            if(special[i][j] > needs[j])
                break;
        }
        //当前礼包可以购买
        if(j == needs.size())
        {
            vector<int> temp_needs(needs.size());
            for(int k= 0;k<needs.size();k++)
                temp_needs[k] = needs[k] - special[i][k];
            res = min(res, shoppingOffersWithMap(price, special, temp_needs, hash_map) + special[i][j]);
        }
    }
    hash_map[needs] = res;
    return res;
}

int shoppingOffers(vector<int> &price, vector<vector<int> > &special, vector<int> &needs)
{
    map<vector<int>, int> hash_map;
    return shoppingOffersWithMap(price, special, needs, hash_map);
}

int main(int argc, char const *argv[])
{
    int a[] = {2,5};
    vector<int> price(a, a+2);
    int b1[] = {3,0,5};
    int b2[] = {1,2,10};
    vector<vector<int> > specials;
    vector<int> temp1(b1,b1+3);
    vector<int> temp2(b2,b2+3);
    specials.push_back(temp1);
    specials.push_back(temp2);
    int c[] = {3,2};
    vector<int> needs(c,c+2);
    int res = shoppingOffers(price, specials, needs);
    cout<<res<<endl;
    return 0;
}
