class Solution:
    def twoCitySchedCost(self, costs) -> int:
        num = len(costs)
        res = 0
        chazhi = []
        for i in range(num):
            chazhi.append((i,abs(costs[i][0] - costs[i][1])))
        chazhi.sort(key=lambda x:x[1],reverse=True)
        print(chazhi)
        A_cnt = 0
        B_cnt = 0
        for (i, c) in chazhi:
            if A_cnt == num // 2:
                res += costs[i][1]
                B_cnt += 1
                continue
            if B_cnt == num //2:
                res += costs[i][0]
                A_cnt += 1
                continue
            if costs[i][0] < costs[i][1]:
                res += costs[i][0]
                A_cnt += 1
            else:
                res += costs[i][1]
                B_cnt += 1
        return res

a = Solution()
res = a.twoCitySchedCost([[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]])
print(res)