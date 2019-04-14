#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int minPathSum(vector< vector<int> >& grid)
{
    vector< vector<int> > res;
    res.resize(grid.size());
    for(int i =0 ;i<res.size();i++)
    {
        res[i].resize(grid[i].size());
    }
    res[0][0] = grid[0][0];
    for(int i = 1;i<res.size();i++)
        res[i][0] = grid[i][0] + res[i-1][0];
    for(int j = 1;j<res[0].size();j++)
        res[0][j] = grid[0][j] + res[0][j-1];
    for(int i = 1; i<res.size();i++)
    {
        for(int j=1;j<res[i].size();j++)
        {
            res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
        }
    }
    return res[res.size()-1][res[0].size()-1];
}

int main()
{
    int a[][3] = {{1,3,1},{1,5,1},{4,2,1}};
    vector< vector<int> > data;
    data.resize(3);
    for(int i = 0;i<data.size();i++)
    {
        for(int j =0; j<3; j++)
            data[i].push_back(a[i][j]);
    }
    int res = minPathSum(data);
    cout<<res<<endl;
    return 0;
}