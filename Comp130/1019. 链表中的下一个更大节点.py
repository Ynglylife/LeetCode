# 本题与数组中寻找每个元素下一个更大值是一样的，只要把链表先转换为数组即可；
# 数组去寻找，维护一个递减栈，每次遍历到一个元素，弹出比当前元素小的所有元素，弹出元素的下一个更大值就是当前遍历元素。
class Solution:
    def nextLargerNodes(self, head):
        temp_ptr = head
        ptr_index = {}
        i = 0
        while(temp_ptr):
            ptr_index[temp_ptr] = i 
            temp_ptr = temp_ptr.next
            i += 1
        res = [0 for j in range(i)]
        stack = []
        temp_ptr = head
        while(temp_ptr):
            while len(stack)!=0 and temp_ptr.val > stack[-1].val:
                temp = stack.pop()
                res[ptr_index[temp]] = temp_ptr.val
            stack.append(temp_ptr)
            temp_ptr = temp_ptr.next
        return res