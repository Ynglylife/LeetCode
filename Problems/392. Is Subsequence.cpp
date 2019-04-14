#include<iostream>
#include<string>

using namespace std;

bool isSubsequence(string s, string t)
{
    if(s.size() == 0)
        return true;
    char c = s[0];
    int j = 0;
    for(;j<t.size();j++)
    {
        if(c == t[j])
            break;
    }
    if(j != t.size())
    {
        return isSubsequence(s.substr(1,s.size() -1),t.substr(j+1,t.size() -j-1));
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s = "axc";
    string t = "ahbgdc";
    bool res = isSubsequence(s, t);
    cout<<res<<endl;
    return 0;
}
