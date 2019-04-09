#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>
using namespace std;

vector<int> uni1(vector<int> arr)
{
    sort(arr.begin(),arr.end());
    vector<int>::iterator iter = unique(arr.begin(), arr.end());
    arr.erase(iter, arr.end());
    return arr;
}

vector<int> uni2(vector<int> arr)
{
    map<int, int> infos;
    for(int i =0;i<arr.size();i++)
    {
        if(infos.find(arr[i]) == infos.end())
            infos.insert(make_pair(arr[i], 1));
    }
    vector<int> res;
    for(map<int,int>::iterator it = infos.begin(); it != infos.end();it++)
    {
        res.push_back(it->first);
    }
    return res;
}

int main()
{
    string strs;
    while(1)
    {
        getline(cin,strs);
        string buf;
        stringstream ss(strs);
        vector<int> data;
        while(ss>>buf)
        {
            data.push_back(atoi(buf.c_str()));
        }
        vector<int> res = uni1(data);
        for(int i = 0;i<res.size();i++)
        {
            cout<<res[i];
        }
    }
    return 0;
}