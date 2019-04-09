class Solution:
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        flag = 0
        start = [0,0]
        end = [0,0]
        _max = 0
        obstacles = set(map(tuple,obstacles))
        for command in commands:
            if command < 0:
                if command == -1:
                    flag = (flag + 1) % 4
                else:
                    flag = (flag - 1) % 4
                continue
            for k in range(command):
                if flag == 0:
                    end[1] = start[1] + 1
                if flag == 1:
                    end[0] = start[0] + 1
                if flag == 2:
                    end[1] = start[1] - 1
                if flag == 3:
                    end[0] = start[0] - 1
                if tuple(end) in obstacles:
                    end = start[:]
                    break
                start = end[:]
                _max = max(_max , start[0]**2 + start[1]**2)
        return _max

if __name__ == "__main__":
    commands = [4,-1,4,-2,4]
    obstacles = [[2,4]]
    a = Solution()
    _max = a.robotSim(commands,obstacles)
    print(_max)     