// Problem 1: Two Sum
// https://leetcode.com/problems/two-sum/

var twoSumJs = function(nums, target) {
  // 使用迴圈單層迴圈
  for (let i = 0; i < nums.length; i++) {
    // 如果 希望的值(目標減去當前數值) 在這個 array 中 且 不是同一個位置的值(index 不相同)
    // 就視為找到答案, 直接 return
    const complement = target - nums[i];
    const complementIndex = nums.indexOf(complement);

    if (complementIndex !== -1 && i !== complementIndex) {
      return [i, complementIndex];
    }
  }
  return [];
};
