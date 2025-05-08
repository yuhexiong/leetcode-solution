# Problem 3540: Minimum Time to Visit All Houses
# https://leetcode.com/problems/minimum-time-to-visit-all-houses/

from typing import List


class Solution:
    def min_total_time(self, forward: List[int], backward: List[int], queries: List[int]) -> int:
        n = len(forward)

        # 先整理 forward 和 backward 兩個 list 的前綴總和避免重複使用 sum
        forward_presum = []
        curr_presum = 0
        for i in range(n):
            curr_presum += forward[i]
            forward_presum.append(curr_presum)

        backward_presum = []
        curr_presum = 0
        for i in range(n):
            curr_presum += backward[i]
            backward_presum.append(curr_presum)

        total_time = 0
        # 跑迴圈查看路線
        for i in range(len(queries)):
            # 起始 index 為上一個據點，如果是第 0 個值則最初由 0 開始
            from_index = queries[i-1] if i > 0 else 0
            to_index = queries[i]

            if from_index == to_index:
                # 如果沒有改變位置，則不用計算
                continue
            elif from_index < to_index:
                # 如果起始 index 小於結束 index
                # 利用 presum 依路徑計算每段加總，注意 index 為 -1 時應該定義路長為 0
                forward_time = forward_presum[to_index-1] - \
                    (forward_presum[from_index-1] if from_index > 0 else 0)
                backward_time = backward_presum[-1] - \
                    backward_presum[to_index] + backward_presum[from_index]
            else:
                # 如果起始 index 大於結束 index
                # 利用 presum 依路徑計算每段加總，注意 index 為 -1 時應該定義路長為 0
                forward_time = forward_presum[-1] - forward_presum[from_index-1] + (
                    forward_presum[to_index-1] if to_index > 0 else 0)
                backward_time = backward_presum[from_index] - \
                    backward_presum[to_index]

            # 選擇順時針和逆時針中較小的加總
            total_time += min(forward_time, backward_time)

        # 回傳總時長
        return total_time
