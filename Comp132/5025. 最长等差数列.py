from collections import defaultdict
# DP解法，dp[i][j] = dp[j][k] + 1 s.t. A[i]-A[k] = A[k] - A[j]
# i,j 表示以i和j结尾的等差序列
# 由于给定的数组中，存在重复数字，所以在构建value->index的映射关系时，需要将所有的index都存起来。 
class Solution:
    def longestArithSeqLength(self, A):
        a_map = defaultdict(lambda:[])
        for index,item in enumerate(A):
            a_map[item].append(index)
        length = len(A)
        dp = [[2 for i in range(length)] for j in range(length)]
        res = 2
        for i in range(length-1, -1, -1):
            for j in range(i+1, length):
                if (2*A[j] - A[i]) in a_map:
                    for index in a_map[2*A[j] - A[i]]:
                        if index >j:
                            dp[i][j] = max(dp[i][j],dp[j][index] + 1)
                    if res < dp[i][j]: 
                        print(A[i],' ',A[j])
                        res = dp[i][j]
        return res