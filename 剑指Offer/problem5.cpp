#include<iostream>
using namespace std;

class Solution{
public:
    //替换空格
    void replaceSpace(char* str, int length)
    {
        int spaces_count = 0;
        for (int i =0;i<length;i++)
        {
            if (str[i] == ' ')
                spaces_count++;
        }
        for(int i=length-1;i>=0;i--)
        {
            if (str[i] == ' ')
            {
                str[i+spaces_count*2] = '0';
                str[i+spaces_count*2-1] = '2';
                spaces_count--;
                str[i+spaces_count*2] = '%';
            }   
            else
                str[i+spaces_count*2] = str[i];
        }
    }
    //合并有序数组
    void merge(int a1[], int length1, int a2[], int length2)
    {
        int pre2 = length2-1;
        for (int i = length1-1; i >= 0 and pre2 >=0;)
        {
            if(a1[i] < a2[pre2])
            {
                a1[i+pre2+1] = a2[pre2];
                pre2--;
            }
            else
            {
                a1[i+pre2+1] = a1[i];
                i--;
            }
        }
    }
};

int main()
{
    Solution *a = new Solution();
    char str[100] = " We are happy"; 
    //a->replaceSpace(str, 12);
    //cout<<str<<endl;
    int a1[100] = {1,2,6,9,10};
    int length1 = 5;
    int a2[10] = {1,3,4,6,7,8,11};
    int length2 = 7;
    a->merge(a1,length1,a2,length2);
    for (int i = 0;i<length1+length2;i++)
        cout<<a1[i]<<' ';
    cout<<endl;
    return 0;
}
