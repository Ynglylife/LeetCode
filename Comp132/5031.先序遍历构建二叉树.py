import re
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 递归求解，切分为左右自树，然后递归调用
class Solution:

    def getSubstr(self, sub_strs):
        sub_str = ''
        for item in sub_strs:
            if item == '':
                sub_str += '-'
            else:
                sub_str += item
        return sub_str
    
    def recoverFromPreorder(self, S: str) -> TreeNode:
        if '-' not in S:
            root = TreeNode(S)
            return root
        indexs = []
        S_len = len(S)
        for i in range(1, S_len-1):
            if S[i] == '-' and S[i-1]!='-' and S[i+1] != '-':
                indexs.append(i)
        if len(indexs) == 1:
            start = indexs[0]
            end = S_len
            sub_strs = S[start+1:end].split('-')
            sub_str = self.getSubstr(sub_strs)
            root = TreeNode(S[:start])
            root.left = self.recoverFromPreorder(sub_str)
        else:
            start = indexs[0]
            end = indexs[1]
            sub_strs1 = S[start+1:end].split('-')
            sub_str1 = self.getSubstr(sub_strs1)
            root = TreeNode(S[:start])
            sub_strs2 = S[end+1:].split('-')
            sub_str2 = self.getSubstr(sub_strs2)
            root.right = self.recoverFromPreorder(sub_str2)
            root.left = self.recoverFromPreorder(sub_str1)
        return root

a = Solution()
a.recoverFromPreorder("10-1--8---8----1-----2")