# Problem 3899: Angles of a Triangle
# https://leetcode.com/problems/angles-of-a-triangle/

import math


class Solution:
    def internal_angles(self, sides: list[int]) -> list[float]:
        # 如果三邊無法構成一個三角形就回傳空陣列
        if (sides[0] + sides[1] <= sides[2]) or \
            (sides[1] + sides[2] <= sides[0]) or \
                (sides[2] + sides[0] <= sides[1]):
            return []

        # 取得角度並排序
        return sorted([
            self.get_angle(sides[0], sides[1], sides[2]),
            self.get_angle(sides[1], sides[2], sides[0]),
            self.get_angle(sides[2], sides[0], sides[1])
        ])

    def get_angle(self, num1: int, num2: int, num3: int) -> float:
        # 使用餘弦定理推算 cos 值
        cos_val = (num2**2 + num3**2 - num1**2) / (2 * num2 * num3)
        # 避免浮點數誤差
        cos_val = max(-1.0, min(1.0, cos_val))
        # 從 cos 值導出弧度
        angle_rad = math.acos(cos_val)
        # 弧度算出角度
        return math.degrees(angle_rad)
