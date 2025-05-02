// Problem 3512: Minimum Operations to Make Array Sum Divisible by K
// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(),nums.end(),0)%k;
    }
};