'''
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:
输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。

注意:
数组的长度不会超过20，并且数组中的值全为正数。
初始的数组的和不会超过1000。
保证返回的最终结果为32位整数。
'''

'''
解析：整个数组可以分为正子集和负子集，然后使得正子集(sum(P))减去负子集(sum(N))结果等于目标值(target):
sum(P) - sum(N) = target
sum(P) + sum(N) = sum(nums)
2 * sum(P) = target + sum(nums)
sum(P) = (target + sum(nums))/2
即，该问题求解转化为求sum(P)等于定值的个数。
使用dp[i]保存加和结果等于i的操作数，那么对于数组nums里面的每个元素n:
dp[i] = dp[i] + dp[i-n]
'''

class Solution:
    def getSum(self, nums, target):
        dp=[0] * (int(target) +1)
        dp[0] = 1
        for n in nums:
            for j in range(target, n-1, -1):
                dp[j] += dp[j-n]
        return dp[target]
    
    def findTargetSumWays(self, nums, S):
        nums_sum = sum(nums)
        target = S + nums_sum
        if target % 2 == 1:
            return 0
        target = target // 2
        print(target)
        res = self.getSum(nums, target)
        return res