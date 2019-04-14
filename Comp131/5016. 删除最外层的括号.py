# 使用栈操作，遇到右括号入栈，左括号出栈，直到栈空时表示当前原语结束，删除外层括号
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        str_stack = []
        str_len = len(S)
        res = ""
        temp = 0
        for i in range(0, str_len):
            if S[i] == '(':
                str_stack.append(S[i])
            else:
                now_str = str_stack.pop()
                if len(str_stack) == 0:
                    res += S[temp+1:i]
                    temp=i+1
        return res