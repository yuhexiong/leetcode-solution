// Problem 3550: Smallest Index With Digit Sum Equal to Index
// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/

#include <vector>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digits_sum = 0;

            while (num > 0) {
                digits_sum += num % 10;
                num /= 10;
                if (digits_sum > i) {
                    break;
                }
            }

            if (digits_sum == i) {
                return i;
            }
        }
        return -1;
    }
};
