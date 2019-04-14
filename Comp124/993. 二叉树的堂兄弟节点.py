class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 关键点为一个是两个节点所在深度相同，第二个是父节点不同，那么获得这两个值之后就可以判断是否是表兄弟节点。使用DFS获取节点的深度和父节点。
class Solution:
    def dfs(self, root, x, depth, parent):
        if root.val == x:
            return(parent, depth)
        res = None
        if root.left:
            res = self.dfs(root.left, x, depth+1, root.val)
        if res ==None and root.right:
            res = self.dfs(root.right, x, depth+1, root.val)
        return res
    def isCousins(self, root, x, y):
        res_x = self.dfs(root, x, 0, None)
        res_y = self.dfs(root, y, 0, None)
        if res_x[0] != res_y[0] and res_x[1] == res_y[1]:
            return True
        return False