# Problem 3324: Find the Sequence of Strings Appeared on the Screen
# https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/

from typing import List


class Solution:
    def string_sequence(self, target: str) -> List[str]:
        # 宣告空陣列為答案
        sequence = []

        # 預設開始的字是空字串
        curr_word = ''

        # 跑迴圈看每個字元
        for t in target:
            # 預設從 a 的前一個編碼開始
            curr_letter = ord('a') - 1

            # 如果目前字母的編碼數小於目標則繼續, 持續 + 1 且加入答案陣列, 到等於時會跳脫迴圈
            while curr_letter < ord(t):
                curr_letter += 1
                sequence.append(curr_word + chr(curr_letter))
            # 字母確定為目標後加入目前字串
            curr_word += chr(curr_letter)

        # 回傳答案
        return sequence
