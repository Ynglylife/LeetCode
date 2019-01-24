#include<iostream>
#include<vector>
using namespace std;

vector<int> countBits(int nums)
{
    vector<int> res;
    res.resize(nums+1);
    res[0] = 0;
    res[1] = 1;
    for(int i = 2; i <= nums;i++)
    {
        if(i%2==1)
            res[i] = res[i-1] + 1;
        else{
            res[i] = res[i/2];
        }
    }
    return res;
}

int main()
{
    int nums = 5;
    vector<int> res = countBits(nums);
    for(int i = 0;i<res.size();i++)
        cout << res[i] <<" ";
    cout<<" ";
    system("pause");
    return 0;
}