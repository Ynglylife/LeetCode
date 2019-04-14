# 对每个元素调用一次获取结果的函数，然后就判断就可以了
class Solution:
    def camelMatch(self, queries, pattern):
        res = []
        for item in queries:
            res_temp = self.getRes(item, pattern)
            res.append(res_temp)
        return res
    def getRes(self, item, pattern):
        i = 0
        j = 0
        while i<len(item) and j <len(pattern):
            if item[i] == pattern[j]:
                i+=1
                j+=1
            elif item[i].isupper():
                return False
            else:
                i += 1
        if j>=len(pattern) and (item[i:].islower() or i>=len(item)):
            return True
        return False