// Problem 3541: Find Most Frequent Vowel and Consonant
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        // 初始化空 vector 為 26 個 0
        vector<int> cnt(26, 0);

        // 計算出現過的字母
        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        int maxVowel = 0;
        int maxNonVowel = 0;

        // 跑迴圈比較，如果是 aeiou 就和 maxVowel 比，其餘的和 maxNonVowel 比，分別找出最大值
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, cnt[i]);
            } else {
                maxNonVowel = max(maxNonVowel, cnt[i]);
            }
        }

        // 將 字母最大值 和 非字母最大值 相加後回傳
        return maxVowel + maxNonVowel;
    }
};