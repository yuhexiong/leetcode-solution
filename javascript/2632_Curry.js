// Problem 2632: Curry
// https://leetcode.com/problems/curry/


/**
 * @param {Function} fn
 * @return {Function}
 */
var curryJs = function(fn) {
  return function curried(...args) {
      // 足夠參數就執行
      if (args.length >= fn.length) {
          return fn(...args);
      }

      // 參數不夠則遞迴
      return function(...nextArgs) {
          return curried(...args, ...nextArgs);
      }
  }
};

