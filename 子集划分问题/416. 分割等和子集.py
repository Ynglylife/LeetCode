'''
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200

示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
 
示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.
'''

# 属于从数组中选取固定元素组成集合，使得集合中元素之和等于固定值问题。
# 使用动态规划的求解思路是维护数组dp[i]，i表示选取元素之和等于i，之后从元素中选取不同元素n：
# 构造dp[i]与dp[i-n]之间的关系。
class Solution:
    def canPartition(self, nums):
        sum_nums = 0
        for i in nums:
            sum_nums += i
        if sum_nums % 2 == 1:
            return False
        sub_sum = sum_nums//2
        return self.getSum(sub_sum, nums)
    #挑选nums里面的元素，使得加和等于sum_need。
    #dp[i] 表示挑选nums里面元素能否等于i，那么对于数组nums里面每个元素n：
    #dp[i] = dp[i-n]，其中dp[0] = 1
    def getSum(self, sum_need, nums):
        dp = [0 for i in range(sum_need+1)]
        dp[0] = 1
        for n in nums:
            for i in range(sum_need,n-1,-1):
                dp[i] = max(dp[i-n],dp[i])
        return dp[sum_need] == 1