#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(),houses.end());
    sort(heaters.begin(),heaters.end());
    int max_rad = 0;
    for(size_t i = 0, j=0; i<houses.size() && j<heaters.size();)
    {
        if(houses[i] >= heaters[j])
        {
            if(j==heaters.size()-1)
            {
                max_rad = max(max_rad, houses[i] - heaters[j]);
                i++;
            }
            else
                j++;
        }
        else{
            if(j==0)
            {
                max_rad = max(max_rad, heaters[j] - houses[i]);
            }
            else{
                int min_rad = min(houses[i] - heaters[j-1], heaters[j] - houses[i]);
                max_rad = max(max_rad, min_rad);
            }
            i++;
        }
    }
    return max_rad;
}

int main()
{
    int h[] = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> houses(h,h+8);
    int he[] = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    vector<int> heaters(he,he+10);
    int max_rad = findRadius(houses,heaters);
    cout<<max_rad<<endl;
    system("pause");
    return 0;
}