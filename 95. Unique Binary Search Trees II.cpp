#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generateTreesWithStartAndEnd(int start, int end)
{
    vector<TreeNode *> res;
    if (start == end)
    {
        res.push_back(NULL);
        return res;
    }
    if (start + 1 == end)
    {
        TreeNode *root = new TreeNode(start);
        res.push_back(root);
        return res;
    }
    for (int i = start; i < end; i++)
    {
        vector<TreeNode *> left = generateTreesWithStartAndEnd(start, i);
        vector<TreeNode *> right = generateTreesWithStartAndEnd(i+1, end);
        for (int k = 0; k < left.size(); k++)
        {
            for (int j = 0; j < right.size(); j++)
            {
                TreeNode *root = new TreeNode(i);
                root->right = right[j];
                root->left = left[k];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode*> res(0);
    if(n==0)
        return res;
    return generateTreesWithStartAndEnd(1, n + 1);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    vector<TreeNode*> res = generateTrees(n);
    return 0;
}
