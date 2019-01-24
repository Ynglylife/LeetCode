#include<iostream>
#include<vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() <= 2)
    return 0;
    int sum = 0;
    int count = 0;
    for(int i =2;i<A.size();i++)
    {
        if(A[i] - A[i-1] == A[i-1] - A[i-2])
        {
            count++;
            sum += count;
        }
        else
        {
            count = 0;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    
    system("pause");
    return 0;
}
