// Problem 682: Baseball Game
// https://leetcode.com/problems/baseball-game/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        // 宣告 int vector
        vector<int> nums;

        // 跑迴圈看 operations 裡面的值，依照題意處理
        for (const string& op : operations) {
            if (op == "C") {
                nums.pop_back();
            } else if (op == "D") {
                nums.push_back(nums.back() * 2);
            } else if (op == "+") {
                nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]);
            } else {
                nums.push_back(stoi(op));
            }
        }

        // 將 nums 的數字加總後回傳
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
};