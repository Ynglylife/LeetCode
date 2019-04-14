
class Solution:
    def queryString(self, S: str, N: int) -> bool:
        for i in range(1, N+1):
            bin_stri = bin(i)
            if not bin_stri[2:] in S:
                return False
        return True