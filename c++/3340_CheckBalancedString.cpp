// Problem 3340: Check Balanced String
// https://leetcode.com/problems/check-balanced-string/

#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        // 宣告奇數總和、偶數總和兩個變數為 0
        int odd_sum = 0;
        int even_sum = 0;

        // 跑迴圈將每個位數都轉換成數字, 並依據 index 為奇數或偶數加入總和
        for (int i = 0; i < num.length(); ++i) {
            int intDigit = num[i] - '0'; // 字符轉換為數字

            if (i % 2 == 0) {
                even_sum += intDigit;
            } else {
                odd_sum += intDigit;
            }
        }

        // 回傳奇數總和是否等於偶數總和
        return odd_sum == even_sum;
    }
};