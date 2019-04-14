class Solution:
    def prefixesDivBy5(self, A):
        res = []
        temp_res = 0
        for i in A:
            temp_res = temp_res*2 + i
            res.append(temp_res%5 == 0)
        return res