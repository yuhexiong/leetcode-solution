// Problem 1526: Minimum Number of Increments on Subarrays to Form a Target Array
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        // index = 0 的值為最初加的數字
        int count = target[0];

        // 每一次增加時都可以加到下降前的 index, 因此只有在 當前數字 小於 前一個數字時需要補加
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                count += target[i] - target[i - 1];
            }
        }
        
        return count;
    }
};