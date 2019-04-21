from collections import deque
class Solution:
    # dfs
    # def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int):
    #     res = []
    #     target = [r0, c0]
    #     index_dis = []
    #     for i in range(R):
    #         for j in range(C):
    #             temp_dis = abs(target[0] - i) + abs(target[1]-j)
    #             index_dis.append([(i,j),temp_dis])
    #     index_dis.sort(key=lambda x:x[1])
    #     for i, _ in index_dis:
    #         res.append([i[0],i[1]])
    #     return res

    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int):
        queue = deque([])
        queue.append([r0, c0])
        is_visit = [[0 for i in range(C)] for j in range(R)]
        res = []
        res.append([r0,c0])
        is_visit[r0][c0] = 1
        dirctions = [(0,1), (0,-1), (1,0),(-1,0)]
        while len(queue) != 0:
            t_x, t_y = queue.popleft()
            for d_x, d_y in dirctions:
                n_x = t_x + d_x
                n_y = t_y + d_y
                if 0 <= n_x < R and 0 <= n_y < C:
                    if is_visit[n_x][n_y] == 0:
                        is_visit[n_x][n_y] = 1
                        res.append([n_x,n_y])
                        queue.append([n_x,n_y])
        return res
a = Solution()
res = a.allCellsDistOrder(R = 2, C = 3, r0 = 1, c0 = 2)
# res = a.allCellsDistOrder(R = 1, C = 100, r0 = 0, c0 = 35)
print(res)