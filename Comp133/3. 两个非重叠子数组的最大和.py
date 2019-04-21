class Solution:
    def maxSumTwoNoOverlap(self, A, L: int, M: int) -> int:

        length = len(A)
        maxll = [0 for i in range(length+1)]
        maxlr = [0 for i in range(length+1)]
        maxml = [0 for i in range(length+1)]
        maxmr = [0 for i in range(length+1)]
        for i in range(length-L,-1,-1):
            maxlr[i] = max(sum(A[i:i+L]), maxlr[i+1])
        for i in range(length -M, -1, -1):
            maxmr[i] = max(sum(A[i:i+M]), maxmr[i+1])
        for i in range(L-1, length):
            maxll[i] = max(sum(A[i-L+1: i+1]), maxll[i-1] )
        for i in range(M-1, length):
            maxml[i] = max(sum(A[i-M+1: i+1]), maxml[i-1] )
        res1 = 0
        for i in range(M-1,length-L):
            res1 = max(maxml[i]+maxlr[i+1], res1)
        res2 = 0
        for i in range(L-1,length-M):
            res2 = max(maxmr[i+1]+maxll[i], res2)
        return max(res1, res2)

a = Solution()
res = a.maxSumTwoNoOverlap([0,6,5,2,2,5,1,9,4], 1, 2)
print(res)