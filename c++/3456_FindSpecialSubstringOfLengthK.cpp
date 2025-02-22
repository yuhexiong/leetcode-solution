// Problem 3456: Find Special Substring of Length K
// https://leetcode.com/problems/find-special-substring-of-length-k/

#include <string>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for (int i = 0; i <= n - k; i++) {
            if (i - 1 >= 0 && s[i - 1] == s[i]) {
                continue;
            }
            if (i + k <= n - 1 && s[i + k - 1] == s[i + k]) {
                continue;
            }
            if (s.substr(i, k) != string(k, s[i])) {
                continue;
            }
            return true;
        }
        return false;
    }
};