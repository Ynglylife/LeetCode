#include<iostream>
#include<vector>
using namespace std;

int numberOfArithmeticsSlices(vector<int>& A)
{
    if(A.size() < 3)
        return 0;
    vector<int> res;
    res.resize(A.size());
    res[0] = 0;
    res[1] = 0;
    res[2] = 1;
    for(int i = 3;i<A.size();i++)
    {
        res[i] = res[i-1] + i - 2 + 1;
    }
    return res[res.size() -1];
}

int main()
{
    int a[] = {1, 2, 3, 8, 9, 10};
    vector<int> data(a, a+4);
    int res = numberOfArithmeticsSlices(data);
    cout<<res<<endl;
    cout<<"hello world"<<endl;
    return 0;
}