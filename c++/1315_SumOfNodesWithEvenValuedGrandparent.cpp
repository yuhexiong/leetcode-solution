// Problem 1315: Sum of Nodes with Even-Valued Grandparent
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    public:
    int processNode(TreeNode *curr, bool isGrandparentEven, bool isParentEven) {
        // 使用遞迴持續往下處理節點
        // 如果已經沒有當前節點，回傳 0
        if (!curr) {
            return 0;
        }

        // 設定目前值為 0，如果 grandparent 是 even 才改為真正的值
        int currValue = 0;
        if (isGrandparentEven) {
            currValue = curr->val;
        }

        // 回傳當前值加上左點所有節點以及右邊所有節點
        return currValue +
               processNode(curr->left, isParentEven, curr->val % 2 == 0) +
               processNode(curr->right, isParentEven, curr->val % 2 == 0);
    }
    int sumEvenGrandparent(TreeNode *root) {
        return processNode(root, false, false);
    }
};
