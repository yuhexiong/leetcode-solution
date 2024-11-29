// Problem 1570: Dot Product of Two Sparse Vectors
// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

#include <vector>
using namespace std;

class SparseVector {
public:
    // 宣告變數 nums1 為 int vector
    vector<int> nums1;

    // 建構時將 nums 放入 nums1
    SparseVector(vector<int> &nums) {
        nums1 = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        // 取出 vec 的 nums, nums 和其他建構式一樣放在 nums1 中, 取出後放入 nums2
        const vector<int>& nums2 = vec.nums1;

        // 宣告答案為 0, 跑迴圈將兩個 vector 的各值相乘後並加入答案
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            ans += nums1[i] * nums2[i];
        }

        // 回傳答案
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);