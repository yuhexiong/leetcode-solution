# Problem 1180: Count Substrings with Only One Distinct Letter
# https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter/



class Solution:
    def subarray_count(self, n: int) -> int:
        # 依長度計算 subarray 的數量
        return n * (n + 1) // 2

    def count_letters(self, s: str) -> int:
        # 預設總數量是 0
        total_cnt = 0
        # 當前數量為 1
        cur_cnt = 1

        # 從第 1 個值開始跑迴圈, 每次審視當前值和前一個值的關係
        for i in range(1, len(s)):
            # 如果現在的字母和前一個相同, 則 + 1
            if s[i] == s[i-1]:
                cur_cnt += 1
            else:
                # 不同則可以開始計算前面這段的 subarray 數量
                total_cnt += self.subarray_count(cur_cnt)
                # 當前數量更新為 1
                cur_cnt = 1

            # 如果是最後一個元素也要計算
            if i == len(s) - 1:
                total_cnt += self.subarray_count(cur_cnt)

        return total_cnt