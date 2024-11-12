// Problem 3115: Maximum Prime Difference
// https://leetcode.com/problems/maximum-prime-difference/

/**
 * @param {number} num
 * @return {boolean}
 */
var isPrimeJs = function (num) {
  if (num === 1) {
    return false;
  }

  let divisor = 2;
  while (divisor * divisor <= num) {
    if (num % divisor === 0) {
      return false;
    }
    divisor += 1;
  }
  return true;
};

/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumPrimeDifferenceJs = function (nums) {
  // 跑迴圈找左邊的質數
  let leftIndex = 0;
  for (let i = 0; i < nums.length; i++) {
    if (isPrimeJs(nums[i])) {
      leftIndex = i;
      break;
    }
  }

  // 跑迴圈從後面往回找右邊的質數, 最多找到 leftIndex 後面一個, 沒找到就使用 leftIndex
  let rightIndex = leftIndex;
  for (let i = nums.length - 1; i > leftIndex; i--) {
    if (isPrimeJs(nums[i])) {
      rightIndex = i;
      break;
    }
  }

  return rightIndex - leftIndex;
};
