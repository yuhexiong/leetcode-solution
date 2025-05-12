// Problem 100: Same Tree
// https://leetcode.com/problems/same-tree/

// Definition for a binary tree node.
class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
  }
}

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
  const checkChildNode = function(r: TreeNode | null, s: TreeNode | null): boolean{
    // 如果兩個都到底了, 回傳true
      if (!r && !s) return true; 
      // 如果只有其中一個到底, 回傳false
      if (!r || !s) return false; 
      // 如果兩個的值相同, 就繼續比對這兩個的左邊 和 這兩個的右邊, 回傳 and 的結果(要左比左相同, 右比右相同才會是true)
      if (r.val === s.val) return (checkChildNode(r.right, s.right) && checkChildNode(r.left, s.left));
      // 其餘都是false
      return false;
  };
  return checkChildNode(p, q);
};