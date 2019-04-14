#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isFit(string s)
{
    if(s.size() == 1)
        return true;
    int len = s.size();
    string sub1,sub2;
    if(len % 2 == 0)
    {
        sub1 = s.substr(0, len/2);
        sub2 = s.substr(len/2,len/2);
    }
    else{
        sub1 = s.substr(0, len/2);
        sub2 = s.substr(len/2+1, len/2);
    }
    reverse(sub2.begin(),sub2.end());
    return sub1 == sub2;
}

int countSubstrings(string s)
{
    vector<int> res;
    res.resize(s.size());
    res[0] = 1;
    for(int i = 1;i<res.size();i++)
    {
        int count = 0;
        for(int j=0; j<=i; j++)
        {
            if(isFit(s.substr(i-j,j+1)))
                count++;
        }
        res[i] = res[i-1] + count;
    }
    return res[res.size() - 1];
}

int main()
{
    string s = "aaa";
    int res = countSubstrings(s);
    cout<<res<<endl;
    return 0;
}