# Problem 3668: Restore Finishing Order
# https://leetcode.com/problems/restore-finishing-order/

from typing import List

class Solution:
    def recover_order(self, order: List[int], friends: List[int]) -> List[int]:
        # 宣告空 list
        finish_order = []

        # 依照 order 的順序跑迴圈, 如果目前值在 friends 內, 就加入 finish_order
        for o in order:
            if o in friends:
                finish_order.append(o)

        return finish_order