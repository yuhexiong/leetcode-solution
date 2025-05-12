# Problem 3535: Unit Conversion II
# https://leetcode.com/problems/unit-conversion-ii/

from collections import defaultdict
from typing import List

class Solution:
    def query_conversions(self, conversions: List[List[int]], queries: List[List[int]]) -> List[int]:
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

        # 跑迴圈處理每個 conversions
        for source, target, factor in conversions:
            process_source_conv(source, target, factor)

        # 前面段與 Unit Conversion I 相同
        # 跑迴圈依題意比較每組 a, b 的值並加入 query_conv
        query_conv = []
        for unit_a, unit_b in queries:
            query_conv.append(base_unit_conv[unit_b] * pow(base_unit_conv[unit_a], MOD - 2, MOD) % MOD)

        # 回傳答案
        return query_conv


