# Problem 3667: Sort Array By Absolute Value
# https://leetcode.com/problems/sort-array-by-absolute-value/description/

from typing import List

class Solution:
    def sort_by_absolute_value(self, nums: List[int]) -> List[int]:
        # 使用 lambda 將指定排序條建設為絕對值的值
        return sorted(nums, key=lambda x: abs(x))