// Problem 2723: Add Two Promises
// https://leetcode.com/problems/add-two-promises/

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromisesJs = async function (promise1, promise2) {
  // 使用 Promise.all 讓兩個 Promise 同步處理, 並 await 兩者的結果再相加
  const [num1, num2] = await Promise.all([promise1, promise2]);
  return num1 + num2;
};
