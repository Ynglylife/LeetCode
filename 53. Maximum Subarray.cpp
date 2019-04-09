#include<iostream>
#include<vector>
using namespace std;

//维护max表示连续子序列的最大值，连续子序列之和小于等于0时重新开始。
int maxSubArray(vector<int>& nums)
{
    int max = nums[0];
    int sum = nums[0];
    for(int i = 1;i<nums.size();i++)
    {
        if(sum < 0)
            sum = nums[i];
        else
            sum += nums[i];
        if(max < sum)
            max = sum;
    }
    return max;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
}

int main()
{
    /*int a[] = {8,-19,5,-4,20};
    vector<int> data(a, a+5);
    int res = maxSubArray(data);
    cout<<res<<endl;*/
    char A = 'A';
    cout.put('A');
    system("pause");
    return 0;
}