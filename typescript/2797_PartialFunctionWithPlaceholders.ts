// Problem 2797: Partial Function with Placeholders
// https://leetcode.com/problems/partial-function-with-placeholders/

/**
 * @param {Function} fn
 * @param {Array} args
 * @return {Function}
 */
var partial = function (fn, args) {
  let restArgIndex = 0;

  return function (...restArgs) {
    for (let i = 0; i < args.length; i++) {
      if (args[i] === '_') {
        args[i] = restArgs[restArgIndex];
        restArgIndex++;
      }
    }

    return fn(...args, ...restArgs.slice(restArgIndex));
  }
};