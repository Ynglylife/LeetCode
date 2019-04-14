#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int index = 0;
    if(flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        flowerbed[0] = 1;
        index++;
    }
    for (int i = 1; i < flowerbed.size()-1; i++)
    {
        if (flowerbed[i] == 1)
        {
            if (flowerbed[i - 1] == 1 || flowerbed[i + 1] == 1)
                return false;
        }
        else
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                index++;
            }
                
        }
    }
    if(flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0)
    {
        index ++;
        flowerbed[flowerbed.size() -1] = 1;
    }
    if (index >= n)
        return true;
    return false;
}

int main()
{
    int data[] = {0, 0};
    vector<int> flowerbed(data, data + 2);
    bool res = canPlaceFlowers(flowerbed, 2);
    cout << res << endl;
    system("pause");
    return 0;
}