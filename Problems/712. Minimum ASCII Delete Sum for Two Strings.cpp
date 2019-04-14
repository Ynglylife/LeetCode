#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int minimumDeleteSum(string s1, string s2)
{
    vector<vector<int> > res;
    res.resize(s1.size()+1);
    for(int i = 0;i<res.size();i++)
        res[i].resize(s2.size()+1);
    res[0][0] = 0;
    for(int i = 1;i<res[0].size();i++)
        res[0][i] = res[0][i-1] + s2[i-1];
    for(int i = 1;i<res.size();i++)
    {
        res[i][0] = res[i-1][0] + s1[i-1];
        for(int j=1;j<res[i].size();j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                res[i][j] = res[i-1][j-1];
            }
            else{
                res[i][j] = min(res[i-1][j] + s1[i-1], res[i][j-1] + s2[j-1]);
            }
        }
    }
    return res[res.size()-1][res[0].size()-1];
}

int main(int argc, char const *argv[])
{
    string s1("sea");
    string s2("eat");
    int res = minimumDeleteSum(s1,s2);
    cout<<res<<endl;
    return 0;
}
