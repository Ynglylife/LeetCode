#include<iostream>
#include<vector>
using namespace std;

//1. 使用C(n,m)计算n行m个数，二项式定理
//2. 递归实现，超时

//3. 二维数组实现

vector<int> getRow(int rowIndex)
{
    vector<int> res;
    res.resize(rowIndex+1);
    res[0] = res[rowIndex] = 1;
    for(int i = 1; i <= rowIndex/2; i++)
    {
        res[i] = res[rowIndex - i] = (unsigned long)res[i - 1]*(unsigned long)(rowIndex - i + 1)/i;
    }
    return res;
}

ostream& operator<<(ostream& output, vector<int> res)
{
    for(int i=0;i<res.size();i++)
        output<<res[i]<<" ";
    return output;
}

int main()
{
    int row_index = 4;
    vector<int> res = getRow(row_index);
    cout<<res<<endl;
    //cout<<C(13,12)<<endl;
    return 0;
}