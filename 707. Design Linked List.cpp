#include<iostream>

using namespace std;

class MyLinkedNode{
public:
    MyLinkedNode(int a=0, MyLinkedNode* p=NULL):val(a),next(p){}
    int val;
    MyLinkedNode* next;
};

class MyLinkedList {
    friend ostream& operator<<(ostream&, MyLinkedList*);
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        MyLinkedNode *node = new MyLinkedNode();
        front = node;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        MyLinkedNode *pre = this->front;
        int i;
        for(i = 0;i<index && pre->next!=NULL;pre = pre->next,i++);
        if(pre->next)
            return pre->next->val;
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedNode *node = new MyLinkedNode(val);
        node->next = this->front->next;
        this->front->next = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedNode *node = new MyLinkedNode(val);
        MyLinkedNode *pre = this->front;
        for(;pre->next != NULL;pre = pre->next);
        node->next = pre->next;
        pre->next = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        MyLinkedNode * node = new MyLinkedNode(val);
        MyLinkedNode *pre = this->front;
        int i;
        for(i = 0;i<index && pre->next!=NULL;pre = pre->next,i++);
        if(i == index)
        {
            node->next = pre->next;
            pre->next = node;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        MyLinkedNode *pre = this->front;
        int i;
        for(i = 0;i<index && pre->next!=NULL;pre = pre->next,i++);
        if(pre->next)
        {
            MyLinkedNode *del = pre->next;
            pre->next = pre->next->next;
            delete del;
        } 
    }
    bool isEmpty() {
        if(this->front == NULL)
            return true;
        return false;
    }
private:
    MyLinkedNode* front;
};

ostream& operator<<(ostream& output, MyLinkedList* link)
{
    MyLinkedNode* pre = link->front;
    for(pre = pre->next ;pre;pre = pre->next)
    {
        output<< pre->val <<" ";
    }
    output<<endl;
    return output;
}

int main()
{
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtHead(1);
    cout<<linkedList;
    linkedList->addAtTail(3);
    cout<<linkedList;
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    cout<<linkedList;
    int val = linkedList->get(1);            //返回2
    cout<<val<<endl;
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    cout<<linkedList;
    val = linkedList->get(1);            //返回3
    cout<<val<<endl;
    /*linkedList->addAtHead(1);
    cout<<linkedList;
    linkedList->addAtIndex(1,2);
    cout<<linkedList;
    int val = linkedList->get(1);
    cout<<val<<endl;
    val = linkedList->get(0);
    cout<<val<<endl;
    val = linkedList->get(2);
    cout<<val<<endl;*/
    system("pause");
    return 0;
}