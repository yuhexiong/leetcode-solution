# Problem 2782: Number of Unique Categories
# https://leetcode.com/problems/number-of-unique-categories/

from typing import Optional

# Definition for a category handler.
class CategoryHandler:
    def have_same_category(self, a: int, b: int) -> bool:
        pass


class Solution:
    def number_of_categories(self, n: int, category_handler: Optional[CategoryHandler]) -> int:
        # 預設 same_category 數量是 0
        same_category = 0

        # 從第 1 個 index 開始跑, 因為兩個才能比較是否同分類, 所以略過 index 0
        for i in range(1, n):
            # 第二個迴圈跑在他之前的數, 只要有一個同分類就停止尋找並免重覆計算
            for j in range(0, i):
                if category_handler.have_same_category(i, j):
                    same_category += 1
                    break

        # n 減去 same_category 即為最後 distinct category 的數量
        return n - same_category
