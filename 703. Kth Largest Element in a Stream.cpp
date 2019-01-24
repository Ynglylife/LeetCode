#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

//使用优先级队列，队列中从大到小保存K个元素。
class KthLargest{
public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for(vector<int>::iterator i=nums.begin();i!=nums.end();i++)
        {
            this->data.push(*i);
            if(this->data.size() > this->k)
                this->data.pop();
        }
    }
    int add(int val)
    {
        this->data.push(val);
        int index = 0;
        if(this->data.size() > this->k)
                this->data.pop();
        cout << this->data.top()<<endl;
        return this->data.top();
    }
    priority_queue<int, vector<int>, greater<int>> data;
    int k;
};

int main()
{
    int k = 3;
    int arr[] = {4,5,8,2};
    vector<int> vec(arr, arr+4);
    KthLargest *kthLargest = new KthLargest(3, vec);
    kthLargest->add(3);   // returns 4
    kthLargest->add(5);   // returns 5
    kthLargest->add(10);  // returns 5
    kthLargest->add(9);   // returns 8
    kthLargest->add(4);   // returns 8
    system("pause");
    return 0;
}