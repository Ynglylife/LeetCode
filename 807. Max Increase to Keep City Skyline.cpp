#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int maxIncreaseKeepingSkyling(vector<vector<int>> &grid)
{
    vector<int> hor(grid[0].size());
    vector<int> ver(grid.size());
    int res = 0;
    for(int i = 0;i<grid.size();i++)
    {
        for(int j = 0;j<grid[i].size();j++)
        {
            if(grid[i][j] > hor[i])
                hor[i] = grid[i][j];
            if(grid[i][j] > ver[j])
                ver[j] = grid[i][j];
        }
    }
    for(int i = 0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            res += min(hor[i], ver[j]) - grid[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> grid(4);
    int a[][4] = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    for(int i = 0;i<4;i++)
    {
        grid[i].resize(4);
        copy(a[i],a[i]+4,grid[i].begin());
    }
    int res = maxIncreaseKeepingSkyling(grid);
    cout<<res<<endl;
    system("pause");
    return 0;
}