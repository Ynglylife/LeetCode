'''
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 

注意:

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000
'''

class Solution:
    def isPartition(self,A, k, target, cursum, isused, innerStart):
        if k==0:
            return True
        elif cursum == target:
            return self.isPartition(A, k-1, target,0,isused,0)
        for i in range(innerStart, len(A)):
            if not isused[i]:
                isused[i] = True
                if self.isPartition(A, k, target, cursum+A[i], isused, i+1):
                    return True
                isused[i] = False
        return False
    
    def canPartitionKSubsets(self, A, k):   
        A_sum = 0
        A_len = len(A)
        for i in range(A_len):
            A_sum += A[i]
        if A_sum % k != 0:
            return False
        isused = [False for i in range(A_len)]
        return self.isPartition(A, k, A_sum//k, 0, isused, 0)