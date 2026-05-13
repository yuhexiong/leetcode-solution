# Problem 3894: Traffic Signal Color
# https://leetcode.com/problems/library-late-fee-calculator/

class Solution:
    def trafficSignal(self, timer: int) -> str:
        # 依照提議判斷數字並給出答案
        if timer == 0:
            return "Green"
        elif timer == 30:
            return "Orange"
        elif 30 < timer and timer <= 90:
            return "Red"
        return "Invalid"
