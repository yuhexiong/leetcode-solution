# Problem 3581: Count Odd Letters from Number
# https://leetcode.com/problems/count-odd-letters-from-number/

from collections import Counter


class Solution:
    def count_odd_letters(self, n: int) -> int:
        # 設定將數字轉換成字母的字典
        num_list = {0: "zero", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine"}

        # 跑迴圈使用字典將數字轉字母
        characters = ''
        for c in str(n):
            characters += num_list[int(c)]

        # 使用 counter 計算字母出現的次數
        counts = Counter(characters)

        # 過濾出只出現單數次的字母，並加總
        odd_count = sum(1 for cnt in counts.values() if cnt % 2 == 1)

        # 回傳答案
        return odd_count