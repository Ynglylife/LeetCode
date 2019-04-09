class Solution:
    def getSum(self, nums, target):
        if len(nums) == 1 and nums[0] != target:
            return 0
        if len(nums) == 1 and nums[0] == target:
            return 1
        res = self.getSum(nums[1:], target) + self.getSum(nums[1:], target-nums[0])
        print(res)
        return res
    
    def findTargetSumWays(self, nums, S):
        nums_sum = sum(nums)
        target = S + nums_sum
        if target % 2 == 1:
            return 0
        target = target / 2
        print(target)
        res = self.getSum(nums, target)
        return res

if __name__ == '__main__':
    a = Solution()
    print(a.findTargetSumWays([1,1,1,1,1], 3))