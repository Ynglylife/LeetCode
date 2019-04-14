import queue
# 解析：从所有非2节点开始dfs，如果可以到达2节点，表示当前节点可以被传染，返回距离
# 否则，就是不能被传染，返回-1，只要有返回-1的节点，原函数就返回-1
class Solution:
    def bfs(self, grid, x, y):
        visit = [[0 for i in range(len(grid[0]))]for j in range(len(grid))]
        q = queue.Queue(100)
        q.put([x,y,0])
        direct = [[-1,0],[1,0],[0,-1],[0,1]]
        while not q.empty():
            now = q.get()
            now_x = now[0]
            now_y = now[1]
            now_step = now[2]
            visit[now_x][now_y] = 1
            for item in direct:
                next_x = now_x + item[0]
                next_y = now_y + item[1]
                if 0 <= next_x < len(grid) and 0 <= next_y < len(grid[0]):
                    if visit[next_x][next_y]:
                        continue
                    if grid[next_x][next_y] == 2:
                        return now_step+1
                    if grid[next_x][next_y] == 1:
                        q.put([next_x, next_y, now_step+1])
        return -1
        
    def orangesRotting(self, grid):
        res_max = -1
        flag = False
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    flag = True
        if flag == False:
            return 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    res = self.bfs(grid, i, j)
                    if res == -1:
                        return -1
                    res_max = max(res_max, res)
        return res_max
    
a = Solution()
res = a.orangesRotting([[2,1,1],[1,1,1],[1,1,1]])
print(res)        