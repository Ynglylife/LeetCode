//求解数组中的重复数字，数组长度为n，所有数字在0～n-1范围内。找出重复数字

#include <iostream>
using namespace std;

bool getDuplicate(int A[], int length, int *duplication)
{
    /*边界情况判定*/
    if (length == 0 or A == nullptr)
        return false;
    for (int i = 0; i < length; i++)
        if (A[i] < 0 or A[i] >= length)
            return false;
    for(int i=0; i<length;)
    {
        if (i != A[i])
        {
            if(A[i] == A[A[i]])
            {
                *duplication = A[i];
                return true;
            }
            int temp = A[i];
            A[i] = A[temp];
            A[temp] = temp;
        }
        else
           i++; 
    }
    return false;
}

int main()
{
    int *a;
    int duplication = 0;
    cout<<getDuplicate(a, 6, &duplication)<<endl;
    return 0;
}