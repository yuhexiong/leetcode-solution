# Problem 3687: Library Late Fee Calculator
# https://leetcode.com/problems/library-late-fee-calculator/

from typing import List

class Solution:
    def late_fee(self, days_late: List[int]) -> int:
        # 初始化所有費用為 0
        total_fee = 0

        # 跑迴圈依照題意將指定倍數的費用加入所有費用
        for day_late in days_late:
            if day_late == 1:
                total_fee += 1
            elif 2 <= day_late and day_late <= 5:
                total_fee += 2 * day_late
            else:
                total_fee += 3 * day_late

        # 回傳所有費用
        return total_fee