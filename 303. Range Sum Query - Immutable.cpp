#include<iostream>
#include<vector>

using namespace std;

class NumArray{
public:
    NumArray(vector<int> nums){
        data.resize(nums.size());
        for(int i=0;i<nums.size();i++)
            data[i] = nums[i];
    }
    int sumRange(int i, int j){
        int res = 0;
        for(;i<=j;i++)
            res += this->data[i];
        return res;
    }
    vector<int> data;
};

int main()
{
    int data[] = {-2,0,3,-5,2,-1};
    vector<int> nums(data,data+6);
    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(2,5);
    cout<<param_1<<endl;
    system("pause");
    return 0;
}