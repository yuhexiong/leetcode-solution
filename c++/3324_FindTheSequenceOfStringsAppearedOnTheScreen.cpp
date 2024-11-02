// Problem 3324: Find the Sequence of Strings Appeared on the Screen
// https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        // 宣告空的答案陣列
        vector<string> sequence;

        // 開始的字串為空
        string currWord = "";

        // 遍歷每個字元
        for (char t : target) {
            // 從 'a' 的前一個開始
            int currLetter = 'a' - 1;

            // 當目前字母的編碼數小於目標，則繼續
            while (currLetter < t) {
                currLetter++;
                sequence.push_back(currWord + static_cast<char>(currLetter));
            }

            // 更新當前字串
            currWord += static_cast<char>(currLetter);
        }

        // 返回結果
        return sequence;
    }
};