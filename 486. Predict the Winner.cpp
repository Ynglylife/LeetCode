#include <iostream>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int> &nums)
{
    if(nums.size() == 0)
        return true;
    vector<vector<int>> res(nums.size());
    for (int i = 0; i < nums.size(); i++)
        res[i].resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
            res[i][i] = nums[i];
    for (int l = 1; l < nums.size(); l++)
    {
        for (int i = 0; i + l < nums.size(); i++)
        {
            res[i][i+l] = max(nums[i] - res[i+1][i+l],nums[i+l] - res[i][i+l-1]);
        }
    }
    return res[0][nums.size() -1]>=0;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,5,233,7};
    vector<int> nums(a,a+4);
    bool res = PredictTheWinner(nums);
    cout<<res<<endl;
    system("pause");
    return 0;
}
