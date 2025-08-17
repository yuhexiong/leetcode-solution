# Problem 3682: Minimum Index Sum of Common Elements
# https://leetcode.com/problems/minimum-index-sum-of-common-elements/

from typing import List

class Solution:
    def minimum_sum(self, nums1: List[int], nums2: List[int]) -> int:
        # 宣告空的 dict 紀錄 nums1, nums2 分別的數字對應 index
        nums1_index = {}
        nums2_index = {}

        # 跑迴圈使用 setdefault 紀錄第一次出現位置
        for i, n in enumerate(nums1):
            nums1_index.setdefault(n, i)
        for i, n in enumerate(nums2):
            nums2_index.setdefault(n, i)

        # 如果沒有相同的數字就回傳 -1
        common = set(nums1_index) & set(nums2_index)
        if not common:
            return -1

        # 找出共同元素並計算最小和
        return min(nums1_index[n] + nums2_index[n] for n in common)