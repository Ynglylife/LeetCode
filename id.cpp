#include<iostream>
#include<vector>
#include<map>
using namespace std;

class node{
public:
    int index;
    int num;
};
int getRank(vector<int> pre_food, vector<int> oper, int p)
{
    multimap<int, int> infos;
    for(int i = 0;i<oper.size();i++)
    {
        pre_food[i] += oper[i]; 
    }
    for(int i = 0;i<pre_food.size();i++)
    {
        infos.insert(make_pair(pre_food[i], i));
    }
    int rank = 0;
    for(multimap<int,int>::iterator it=infos.begin(); it != infos.end();it++)
    {
        if(p == it->second)
            return rank + 1;
        rank++;
    }
    return 0;
}

int main()
{
    int a[] = {5,3,1};
    int M = 3;
    int N = 4;
    int P = 2;
    cin>>M>>N>>P;
    vector<int> food;
    for(int i = 0;i<M;i++)
    {
        int temp;
        cin>>temp;
        food.push_back(temp);
    }
    vector<int> oper(food.size(), 0);
    for(int i = 0;i<N;i++)
    {
        char op;
        int index;
        cin>>op>>index;
        if(op == 'A')
            oper[index -1] = 1;
        else
            oper[index - 1] = -1;
    }
    int res = getRank(food, oper, P);
    cout<<res<<endl;
    return 0;
}