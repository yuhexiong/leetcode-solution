# Problem 1874: Minimize Product Sum of Two Arrays
# https://leetcode.com/problems/minimize-product-sum-of-two-arrays/

from typing import List


class Solution:
    def min_product_sum(self, nums1: List[int], nums2: List[int]) -> int:
        # 將 nums1 從小排到大, nums2 從大排到小
        nums1.sort()
        nums2.sort(reverse=True)

        # 跑迴圈將同 index 的數相乘後加入 ans
        ans = 0
        for i in range(len(nums1)):
            ans += nums1[i] * nums2[i]

        # 回傳 ans
        return ans
