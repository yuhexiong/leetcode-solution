// Problem 100: Same Tree
// https://leetcode.com/problems/same-tree/

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return checkChildNode(p, q);
    }

    private boolean checkChildNode(TreeNode r, TreeNode s) {
        // 如果兩個都到底了, 回傳true
        if (r == null && s == null) return true;
        // 如果只有其中一個到底, 回傳false
        if (r == null || s == null) return false;
        // 如果兩個的值相同, 就繼續比對這兩個的左邊 和 這兩個的右邊, 回傳 and 的結果(要左比左相同, 右比右相同才會是true)
        if (r.val == s.val) return checkChildNode(r.right, s.right) && checkChildNode(r.left, s.left);
        // 其餘都是false
        return false;
    }
}