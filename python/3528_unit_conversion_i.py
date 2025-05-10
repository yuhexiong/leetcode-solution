# Problem 3528: Unit Conversion I
# https://leetcode.com/problems/unit-conversion-i/

from collections import defaultdict
from typing import List

class Solution:
    def base_unit_conversions(self, conversions: List[List[int]]) -> List[int]:
        # 設定空陣列為答案
        base_unit_conv = [None for _ in range(len(conversions)+1)]
        # 第 0 筆資料為 1 分 "第 0 筆資料單位"
        base_unit_conv[0] = 1

        MOD = 10**9 + 7

        # 整理反向 dict，可以回推找資料
        reverse_map = defaultdict(list)
        for source, target, factor in conversions:
            reverse_map[target].append((source, factor)) 

        # 設定 dfs function
        def process_source_conv(source, target, factor):
            if base_unit_conv[source] is None:
                # 假如 source 還沒設定，使用 reverse_map 往前設定
                for prev, prev_factor in reverse_map[source]:
                    # 前一個節點使用 process_source_conv 尋找並設定
                    process_source_conv(prev, source, prev_factor)
                    # 直到 source 確定設定完畢
                    if base_unit_conv[source] is not None:
                        break

            # 目標單位設定成 來源乘以倍數
            base_unit_conv[target] = (base_unit_conv[source]*factor)%MOD
            return

        # 跑迴圈處理每個 conversion
        for source, target, factor in conversions:
            process_source_conv(source, target, factor)

        # 回傳答案
        return base_unit_conv



