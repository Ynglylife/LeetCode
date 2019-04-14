#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>

using namespace std;
/**/
int deleteAndEarn(vector<int> &nums)
{
    if(nums.size() == 0)
        return 0;
    int max_value = *max_element(nums.begin(), nums.end());
    vector<int> res(max_value+1, 0), value_count(max_value+1, 0);
    for(auto value:nums)
    {
        value_count[value]++;
    }
    res[1] = value_count[1];
    for(int i = 2;i<=max_value;i++)
    {
        res[i] = max(res[i-2] + value_count[i] * i, res[i-1]);
    }
    return res[max_value];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
