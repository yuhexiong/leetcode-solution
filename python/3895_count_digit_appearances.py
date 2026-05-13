# Problem 3895: Count Digit Appearances
# https://leetcode.com/problems/count-digit-appearances/


class Solution:
    def count_digit_occurrences(self, nums: list[int], digit: int) -> int:
        # 初始化次數為 0
        count = 0

        # 跑迴圈處理每個數字
        for num in nums:
            # 轉成字串
            str_num = str(num)
            # 字串迴圈處理每個位數
            for c in str_num:
                # 字串比對是否相同，相同則加 1
                if str(digit) == c:
                    count += 1

        # 回傳次數
        return count
