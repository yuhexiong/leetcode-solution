# Problem 252: Meeting Rooms
# https://leetcode.com/problems/meeting-rooms/

from typing import List


class Solution:
    def can_attend_meetings(self, intervals: List[List[int]]) -> bool:
        # 將所有會議時間排序
        intervals.sort()

        # 跑迴圈檢查是否有前一個會議的結束時間晚於後一個會議的開始時間, 有的話回傳 False
        for i in range(len(intervals) - 1):
            if intervals[i][1] > intervals[i+1][0]:
                return False

        # 跑迴圈後還沒有回傳代表沒有重疊, 回傳 True
        return True
