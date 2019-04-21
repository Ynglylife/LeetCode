#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x):val(x),right(nullptr),left(nullptr){}
};

class BinaryTree{
public:
    BinaryTree(int value){
        TreeNode* node = new TreeNode(value);
        root = node;
    }
    BinaryTree():root(nullptr){}
    void construct(vector<int>,vector<int>);
    void preOrderTravel() const;
    void inOrderTravel() const;
    void postOrderTravel() const;
    void layerTravel() const;
    void deleteTree(TreeNode*);
private:
    TreeNode* root;
    void _preOrderTravel(TreeNode *)const;
    void _preOrderTravelWithLoop(TreeNode *) const;
    void _inOrderTravel(TreeNode *)const;
    void _inOrderTravelWithLoop(TreeNode* )const;
    void _postOrderTravel(TreeNode *)const;
    void _postOrderTravelWithLoop(TreeNode* )const;
    TreeNode* _construct(vector<int> pre, vector<int> in, int pre_start, int pre_length, int in_start, int in_length);
};

void BinaryTree::preOrderTravel() const{
    this->_preOrderTravelWithLoop(root);
    cout<<"\n"<<endl;
}

void BinaryTree::_preOrderTravel(TreeNode *node)const{
    if(node==nullptr)
        return;
    cout<<node->val<<" ";
    this->_preOrderTravel(node->left);
    this->_preOrderTravel(node->right);
}

void BinaryTree::_preOrderTravelWithLoop(TreeNode* node)const{
    stack<TreeNode*> node_stack;
    TreeNode *temp = node;
    while(temp!=nullptr or not node_stack.empty())
    {
        if(temp == nullptr)
        {
            temp = node_stack.top();
            node_stack.pop();
        }
        cout<<temp->val<<" ";
        if(temp->right != nullptr)
            node_stack.push(temp->right);
        temp = temp->left; 
    }
}

void BinaryTree::inOrderTravel() const{
    this->_inOrderTravelWithLoop(root);
    cout<<"\n"<<endl;
}

void BinaryTree::_inOrderTravel(TreeNode* node)const{
    if(node==nullptr)
        return;
    this->_inOrderTravel(node->left);
    cout<<node->val<<" ";
    this->_inOrderTravel(node->right);
}

void BinaryTree::_inOrderTravelWithLoop(TreeNode* node)const{
    stack<TreeNode*> node_stack;
    TreeNode* temp = node;
    // TreeNode* pre = node;
    while(temp!=nullptr or not node_stack.empty())
    {
        if(temp != nullptr){
            node_stack.push(temp);
            temp = temp->left;
        }
        else{
            temp = node_stack.top();
            cout<<temp->val<<" ";
            node_stack.pop();
            temp = temp->right;
        }

        // if (temp == nullptr)
        // {
        //     temp = node_stack.top();
        //     node_stack.pop();
        //     pre = temp->left;
        // }
        // if(pre == temp->left){
        //     cout<<temp->val<<" ";
        //     pre = temp;
        //     temp = temp->right;
        // }
        // else{
        //     node_stack.push(temp);
        //     temp = temp->left;
        // }
    }
}

void BinaryTree::postOrderTravel() const{
    this->_postOrderTravelWithLoop(root);
    cout<<"\n"<<endl;
}

void BinaryTree::_postOrderTravel(TreeNode* node)const{
    if(node == nullptr)
        return;
    this->_postOrderTravel(node->left);
    this->_postOrderTravel(node->right);
    cout<<node->val<<" ";
}

void BinaryTree::_postOrderTravelWithLoop(TreeNode* node)const{
    TreeNode* temp = node;
    TreeNode* pre = nullptr;
    stack<TreeNode*> node_stack, output;
    node_stack.push(temp);
    while (!node_stack.empty()) {
        TreeNode *curr = node_stack.top();
        output.push(curr);
        node_stack.pop();
        if (curr->left)
            node_stack.push(curr->left);
        if (curr->right)
            node_stack.push(curr->right);
    }
    
    while (!output.empty()) {
        cout << output.top()->val << " ";
        output.pop();
    }
    cout << endl;

    // while (temp or !node_stack.empty()){
    //     if (temp != nullptr)
    //     {
    //         node_stack.push(temp);
    //         temp = temp->left;
    //     }
    //     else{
    //         temp = node_stack.top();
    //         node_stack.pop();
    //         if (temp->right and pre != temp->right){
    //             node_stack.push(temp);
    //             temp = temp->right;
    //         }
    //         else
    //         {
    //             cout<<temp->val<<" ";
    //             pre = temp;
    //             temp = nullptr;
    //         }
    //     }
    // }
}

void BinaryTree::layerTravel() const{
    queue<TreeNode*> node_queue;
    node_queue.push(root);
    while(not node_queue.empty()){
        TreeNode* temp = node_queue.front();
        node_queue.pop();
        cout<<temp->val<<" ";
        if(temp->left)
            node_queue.push(temp->left);
        if(temp->right)
            node_queue.push(temp->right);
    }
    cout<<"\n"<<endl;
}

void BinaryTree::construct(vector<int> pre, vector<int> in)
{
    if(root){
        deleteTree(root);
    }
    int pre_length = pre.size();
    int in_length = in.size();
    this->root = _construct(pre, in, 0, pre_length, 0, in_length);
}

void BinaryTree::deleteTree(TreeNode * temp){
    if(temp == nullptr)
        return;
    deleteTree(temp->left);
    deleteTree(temp->right);
    delete temp;
}

TreeNode* BinaryTree::_construct(vector<int> pre, vector<int> in, int pre_start, int pre_length, int in_start, int in_length)
{
    TreeNode *temp_root = new TreeNode(pre[pre_start]);
    int len = 0;
    for(;in[in_start+len] != pre[pre_start];len++);
    if(len!=0){
        temp_root->left = _construct(pre, in, pre_start+1, len, in_start, len);
    }
    if(pre_length-len-1 != 0)
    {
        temp_root->right = _construct(pre, in, pre_start+len+1, pre_length-len-1, in_start+len+1, in_length-len-1);
    }
    return temp_root;
}

int main()
{
    int a1[] = {1,2,4,7,3,5,6,8};
    int a2[] = {4,7,2,1,5,3,8,6};
    BinaryTree *now = new BinaryTree();
    vector<int> v1(a1,a1+8);
    vector<int> v2(a2,a2+8);
    now->construct(v1,v2);
    now->postOrderTravel();
    //now->inOrderTravel();
    //now->postOrderTravel();
    //now->layerTravel();
    return 0;
}