#include<iostream>
#include<vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}    
};

class Solution {
public:
    //从尾到头打印链表
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;
        while(temp){
            values.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0; i<values.size()/2; i++)
        {
            int temp = values[i];
            values[i] = values[values.size()-1-i];
            values[values.size()-1-i] = temp;
        }
        return values;
    }
};