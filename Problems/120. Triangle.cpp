#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<vector<int>> res;
    res.resize(triangle.size());
    for (int i = 0; i < triangle.size(); i++)
    {
        res[i].resize(triangle[i].size());
    }
    res[0][0] = triangle[0][0];
    for (int i = 1; i < res.size(); i++)
    {
        res[i][0] = res[i - 1][0] + triangle[i][0];
        res[i][res[i].size() - 1] = res[i - 1][res[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
        for (int j = 1; j < res[i].size() - 1; j++)
        {
            res[i][j] = min(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
        }
    }
    int min = res[res.size() - 1][0];
    for (int i = 1; i < res[res.size() - 1].size(); i++)
    {
        if (res[res.size() - 1][i] < min)
            min = res[res.size() - 1][i];
    }
    return min;
}

int main()
{
    vector<vector<int>> data;
    int a1[] = {2};
    int a2[] = {3, 4};
    int a3[] = {6, 5, 7};
    int a4[] = {4, 1, 8, 3};
    vector<int> data1(a1, a1 + 1);
    vector<int> data2(a2, a2 + 2);
    vector<int> data3(a3, a3 + 3);
    vector<int> data4(a4, a4 + 4);
    data.push_back(data1);
    data.push_back(data2);
    data.push_back(data3);
    data.push_back(data4);
    int res = minimumTotal(data);
    cout << res << endl;
    return 0;
}