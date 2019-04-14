#思路：111%k = ((11%k)*10 +1)%k
#且最多循环k次

class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        mod = 1
        for i in range(0,K):
            if mod%K == 0:
                return i+1
            mod = (mod*10+1)%K
        return -1