#efinition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 遍历到当前节点时，求解当前路径上的最大差值，然后递归遍历子孙节点，在子孙节点中寻找差值
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        return self.getRes(root, -1, 100000)

    def getRes(self, root, max_val, min_val):
        if root == None:
            return 0
        temp_res = max(max_val-root.val, root.val-min_val)
        max_val = max(max_val, root.val)
        min_val = min(min_val, root.val)
        left_res = self.getRes(root.left, max_val, min_val)
        right_res = self.getRes(root.right, max_val, min_val)
        return max(temp_res, left_res, right_res)