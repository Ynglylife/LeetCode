'''
思路：首先保证第一段和第四段和相等，然后调整第二和第三段和相等
'''

class Solution(object):
    def canFourPartsEqualSum(self, A):
        if self.canpartsEqualSum(A, 0, len(A)-1, 2) != -1:
            return True
        return False

    def canpartsEqualSum(self, A, start, end, k):
        if k==1:
            i=start
            j = end
            while j>i+1:
                sum_pre = sum(A[start:i+1])
                sum_fol = sum(A[j:end+1])
                if sum_pre < sum_fol:
                    i += 1
                elif sum_pre > sum_fol:
                    j -= 1
                else:
                    if j == i+2:
                        return sum_pre
                    else:
                        i += 1
                        j -= 1
            return -1
        i=start
        j = end
        while j>i+1:
            sum_pre = sum(A[start: i+1])
            sum_fol = sum(A[j:end+1])
            if sum_pre < sum_fol:
                i += 1
            elif sum_pre > sum_fol:
                j -= 1
            else:
                sum_sub = self.canpartsEqualSum(A, i+2, j-2, k-1)
                if sum_sub != -1 and sum_sub == sum_pre:
                    return sum_pre
                i += 1
                j -= 1
        return -1

a = Solution()
a.canFourPartsEqualSum([2,2,5,1,2,1,1,3,1,10,1,1,1,1])