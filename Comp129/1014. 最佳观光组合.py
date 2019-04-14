# 思路：A[i] + A[i-k] + i-k - i = A[i] - i + A[i-k] + i-k
# 那么求解到当前i的最佳观光位置，就是A[i] - i + max({A[i-k] + i-k})，一直维护A[i]+i的最大值，可以使得解法的时间复杂度为O(n)。
class Solution:
    def maxScoreSightseeingPair(self, A):
        max_add = 0
        res = 0
        A_len = len(A)
        for i in range(A_len):
            res = max(res, A[i] - i + max_add)
            temp_add = A[i] + i
            max_add = max(max_add, temp_add)
        return res