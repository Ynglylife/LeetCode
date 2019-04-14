# 子集划分问题，该问题是在子集连续情况下的划分问题，可通过修改非连续的子集划分得到
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
        return False
    
    def canThreePartsEqualSum(self, A):   
        A_sum = 0
        A_len = len(A)
        for i in range(A_len):
            A_sum += A[i]
        if A_sum % 3 != 0:
            return False
        isused = [False for i in range(A_len)]
        return self.isPartition(A, 3, A_sum//3, 0, isused, 0)