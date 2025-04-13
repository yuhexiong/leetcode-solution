// Problem 3516: Find Closest Person
// https://leetcode.com/problems/find-closest-person/

#include <algorithm>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        // 分別計算出 1 和 2 走的距離
        int step_1 = abs(x - z);
        int step_2 = abs(y - z);

        // 依照題意比較大小並回傳值
        if (step_1 < step_2) {
            return 1;
        } else if (step_1 > step_2) {
            return 2;
        } else {
            return 0;
        }
    }
};