#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int rob(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;
    vector<int> res;
    res.resize(nums.size());
    res[0] = nums[0];
    res[1] = max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++)
    {
        res[i] = max(nums[i] + res[i-2],res[i-1]);
    }
    return res[nums.size() - 1];
}

int main()
{
    int a[] = {2,7,9,3,1};
    vector<int> data(a, a+5);
    int res = rob(data);
    cout<<res<<endl;
    system("pause");
    return 0;
}