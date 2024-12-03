# Problem 3369: Design an Array Statistics Tracker
# https://leetcode.com/problems/design-an-array-statistics-tracker/

from collections import deque
from sortedcontainers import SortedList

class StatisticsTracker:

    def __init__(self):
        self.nums = deque()
        self.sorted_nums = SortedList([])
        self.sum_nums = 0
        self.n = 0
        self.counter = {}

    def add_number(self, number: int) -> None:
        self.nums.append(number)
        self.sorted_nums.add(number)
        self.sum_nums += number
        self.n += 1
        if number not in self.counter:
            self.counter[number] = 0
        self.counter[number] += 1

    def remove_first_added_number(self) -> None:
        if self.nums:
            first_num = self.nums[0]
            self.nums.remove(first_num)
            self.sorted_nums.remove(first_num)
            self.sum_nums -= first_num
            self.n -= 1
            self.counter[first_num] -= 1
            if self.counter[first_num] == 0:
                del self.counter[first_num]

    def get_mean(self) -> int:
        return self.sum_nums // self.n if self.n > 0 else 0

    def get_median(self) -> int:
        if self.n == 0:
            return 0
        return self.sorted_nums[self.n//2]

    def get_mode(self) -> int:
        if not self.counter:
            return 0
        max_count = max(self.counter.values())
        modes = [key for key, value in self.counter.items() if value == max_count]
        return min(modes)


# Your StatisticsTracker object will be instantiated and called as such:
# obj = StatisticsTracker()
# obj.add_number(number)
# obj.remove_first_added_number()
# param_3 = obj.get_mean()
# param_4 = obj.get_median()
# param_5 = obj.get_mode()