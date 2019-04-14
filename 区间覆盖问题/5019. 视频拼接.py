# 区间覆盖问题，将所有子区间按照开始时间排序，然后在规定区间内选取结束时间最晚的子区间，直到达到给定区间的段点

class Solution:
    def videoStitching(self, clips, T: int) -> int:
        clips.sort()
        rows_len = len(clips)
        res = 0
        temp = 0
        if clips[0][0] != 0 or clips[-1][1] <T:
            return -1
        row = 0
        while row < rows_len:
            if clips[row][0] > temp:
                return -1
            search = clips[row][1]
            while row < rows_len and clips[row][0]<=temp:
                search = max(search, clips[row][1])
                row += 1
            res += 1
            temp = search
            if temp >= T:
                break;
        return res