// Problem 2722: Join Two Arrays by ID
// https://leetcode.com/problems/join-two-arrays-by-id/

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var joinJs = function (arr1, arr2) {
  // 宣告一個 result 放結果
  const result = {};

  // 整理 arr1, 依 id 為 key, 將値放入 value
  for (const allValue of arr1) {
    result[allValue["id"]] = allValue;
  }

  // 整理 arr2
  for (const allValue of arr2) {
    // 如果目前沒有這個 id 的資料, 就直接放入
    if (!result[allValue["id"]]) {
      result[allValue["id"]] = allValue;
    } else {
      // 如果目前已有這個 id 的資料, 跑迴圈看裡面所有 key 和 value, 更新値
      let newValue = result[allValue["id"]];
      for (const key of Object.keys(allValue)) {
        newValue[key] = allValue[key];
      }
      result[allValue["id"]] = newValue;
    }
  }

  // 回傳這個 result 的 value
  return Object.values(result);
};
