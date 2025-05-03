# Problem 1063: Number of Valid Subarrays
# https://leetcode.com/problems/number-of-valid-subarrays/

from typing import List


class Solution:
    def valid_subarrays(self, nums: List[int]) -> int:
        stack = []
        cnt = 0

        for num in nums:
            # stack 為小於目前為止右邊所有數的數值, 可以做為左端點
            # 如果 num 小於 stack 後面的值就要移除 num 直到大於等於 stack
            while len(stack) > 0 and num < stack[-1]:
                stack.pop()
            # 將 num 加入 stack
            stack.append(num)
            # len(stack) 代表當 num 為最右端點時, 有效的左端點數量
            cnt += len(stack)

        return cnt