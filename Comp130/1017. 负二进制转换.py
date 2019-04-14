# 进制变换，假设目标值为target，首先获取负二进制末位值，该位对应十进制0或者1，那么有(前面所有值) + (0/1) = target
# （前面所有值）= target - (0/1)，从而下一次循环值就是(target-(0/1))//(-2)
class Solution:
    def baseNeg2(self, N: int) -> str:
        res = []
        if N == 0:
            return '0'
        temp = N
        while temp:
            now_value = temp % 2
            res.append(str(now_value))
            temp = (temp - now_value)//(-2)
        res.reverse()
        return ''.join(res)

a = Solution()
res = a.baseNeg2(2)
print(res)