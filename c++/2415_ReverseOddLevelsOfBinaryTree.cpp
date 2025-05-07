// Problem 2415: Reverse Odd Levels of Binary Tree
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

#include <utility>
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
    void dfs(TreeNode *leftNode, TreeNode *rightNode, int level) {
        // 如果沒有子節點，則結束搜尋
        if (!leftNode || !rightNode)
            return;

        // 如果是基數層，交換左右兩個節點的值
        if (level % 2 == 1) {
            swap(leftNode->val, rightNode->val);
        }

        // 左節點的左節點 和 右節點的右節點 (即外側) 進行搜索交換
        // 左節點的右節點 和 左節點的右節點 (即內側) 進行搜索
        dfs(leftNode->left, rightNode->right, level + 1);
        dfs(leftNode->right, rightNode->left, level + 1);
    }

    TreeNode *reverseOddLevels(TreeNode *root) {
        // 如果沒有當前節點則直接回傳 null
        if (!root)
            return nullptr;

        // 從第一層開始進行搜索
        dfs(root->left, root->right, 1);

        return root;
    }
};