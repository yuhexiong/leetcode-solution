// Problem 3536: Maximum Product of Two Digits
// https://leetcode.com/problems/maximum-product-of-two-digits/

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        // 預設第一大和第二大的數字為 0
        int first_digit = 0;
        int second_digit = 0;

        // 跑迴圈將 n 取出個位數後再除以 10 直到 0
        while (n > 0) {
            // 比較數字大小並放入第一大或第二大的數字
            if (n % 10 > first_digit) {
                second_digit = first_digit;
                first_digit = n % 10;
            } else if (first_digit >= n % 10 && n % 10 > second_digit) {
                second_digit = n % 10;
            }
            n /= 10;
        }

        // 將兩數相乘並回傳
        return first_digit * second_digit;
    }
};