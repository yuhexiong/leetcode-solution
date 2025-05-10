# Problem 47: Permutations II
# https://leetcode.com/problems/permutations-ii/

from typing import List


class Solution:
    # 寫一個 dfs 遞迴處理下一個值
    def determine_next_num(self, nums, curr, visited, res):
    # 如果 curr 已填滿就加入 res 後 return
        if len(curr) == len(nums):
            res.append(curr)
            return

        # 決定下一個位數, 有 len(nums) 種可能
        for i in range(len(nums)):
            # 如果是已經使用過的數字, 就檢查下一個
            if visited[i]:
                continue
            # 如果是和上一個重複的數字就不計, 檢查下一個
            if i > 0 and nums[i] == nums[i-1] and not visited[i-1]:
                continue
            # 將 visited 改為 True 並繼續找下下一位數
            visited[i] = True
            self.determine_next_num(nums, curr+[nums[i]], visited, res)
            # 將 visited 改回 False 避免影響下一個可能組合
            visited[i] = False

    def permute_unique(self, nums: List[int]) -> List[List[int]]:
        # 設定結果
        res = []
        # 設定瀏覽過的數字
        visited = [False for _ in range(len(nums))]
        # 將數字排序, 方便檢查同一個數字重複的狀況
        nums.sort()
        
        self.determine_next_num(nums, [], visited, res)

        return res
