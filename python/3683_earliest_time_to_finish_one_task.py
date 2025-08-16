# Problem 3683: Earliest Time to Finish One Task
# https://leetcode.com/problems/earliest-time-to-finish-one-task/

from typing import List

class Solution:
    def earliest_time(self, tasks: List[List[int]]) -> int:
        # 先假設 earliest 是無限大
        earliest = float('inf')

        # 跑迴圈查看每組的結束時間，取出最小的
        for s, t in tasks:
            earliest = min(earliest, s + t)

        # 回傳答案
        return earliest