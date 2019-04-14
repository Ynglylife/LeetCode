# dfs 从边界点开始，标记所有可达节点
from collections import deque
class Solution:
    def numEnclaves(self, A) -> int:
        row_cnt = len(A)
        col_cnt = len(A[0])
        queue = deque([])
        for i in range(row_cnt):
            if A[i][0] == 1:
                A[i][0] = 2
                queue.append((i,0))
            if A[i][col_cnt-1] == 1:
                A[i][col_cnt-1] = 2
                queue.append((i,col_cnt-1))
        for j in range(col_cnt):
            if A[0][j] == 1:
                queue.append((0,j))
                A[0][j] = 2
            if A[row_cnt-1][j] == 1:
                queue.append((row_cnt-1, j))
                A[row_cnt-1][j] = 2
        dirctions = [(0,1), (0,-1), (1,0),(-1,0)]
        while len(queue)!=0:
            temp_x, temp_y = queue.popleft()
            for dirc_x, dirc_y in dirctions:
                next_x = temp_x + dirc_x
                next_y = temp_y + dirc_y
                if 0 <= next_x < row_cnt and 0 <= next_y < col_cnt:
                    if A[next_x][next_y] == 1:
                        A[next_x][next_y] =2
                        queue.append((next_x,next_y))
        res = 0
        for i in range(row_cnt):
            for j in range(col_cnt):
                if A[i][j] == 1:
                    res += 1
        return res

a = Solution()
res = a.numEnclaves([[1,0,1,0,1,1,1,0,1,1,0],[1,0,0,1,1,1,0,0,0,0,1],[1,0,0,0,0,0,0,0,1,0,1],
                     [1,1,0,0,1,1,1,1,1,0,0],[0,0,1,0,0,1,0,1,1,0,0],[0,1,1,1,0,1,1,0,1,0,0],
                     [0,1,0,0,1,1,0,1,0,0,1],[1,1,1,0,1,0,0,1,1,0,0],[0,1,1,0,0,0,1,0,1,0,0],[0,0,0,0,1,0,1,0,1,1,1],
                     [0,1,0,0,0,0,1,1,0,1,1]])
print(res)
