#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int findLongestChain(vector<vector<int> > &pairs)
{
    vector<vector<int> > copy_pairs = pairs;
    stable_sort(copy_pairs.begin(), copy_pairs.end());
    for(int i = 0;i<pairs.size();i++)
    {
        reverse(copy_pairs[i].begin(),copy_pairs[i].end());
    }
    stable_sort(copy_pairs.begin(), copy_pairs.end());
    int pre = 0;
    int count = 1;
    for(int i = 1;i<copy_pairs.size();i++)
    {
        if(copy_pairs[i][1] > copy_pairs[pre][0])
        {
            count++;
            pre = i;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int a1[] = {1,2};
    vector<int> data1(a1,a1+2);
    int a2[] = {3,4};
    vector<int> data2(a2,a2+2);
    int a3[] = {2,3};
    vector<int> data3(a3,a3+2);
    vector<vector<int> > data;
    data.push_back(data1);
    data.push_back(data2);
    data.push_back(data3);
    int res = findLongestChain(data);
    return 0;
}
