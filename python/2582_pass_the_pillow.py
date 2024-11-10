# Problem 2582: Pass the Pillow
# https://leetcode.com/problems/pass-the-pillow/

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        # 以 1 到 n 再回到 2 為單趟, 取餘數
        time %= (n - 1) * 2

        # 如果 time 大於 n - 1, 代表在回程, 先扣掉去程的 n - 1 以後, 用 n 減去剩下的數就是所在的位置
        if time > n - 1:
            time -= n - 1
            return n - time
        # 如果 time 沒有大於 n - 1, 代表在去程, 因為以 1 為開頭所以 time 還要再加 1
        else:
            return time + 1