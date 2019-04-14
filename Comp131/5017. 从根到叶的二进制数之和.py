# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# dfs，记录遍历到当前节点时，路径节点值的二进制结果，然后再遍历子节点
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        return (self.getChild(root, 0) % (int(1e9 + 7)))
    def getChild(self, root, temp):
        if root == None:
            return 0
        if root.right == None and root.left == None:
            return temp*2 + root.val
        res = self.getChild(root.right, temp*2+root.val) + self.getChild(root.left, temp*2+root.val)
        return res