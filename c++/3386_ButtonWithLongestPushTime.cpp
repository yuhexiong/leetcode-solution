// Problem 3386: Button with Longest Push Time
// https://leetcode.com/problems/button-with-longest-push-time/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        // 先設定第一個為起始
        int buttonIndex = events[0][0];
        int longestTime = events[0][1];
        int startTime = events[0][1];

        // 從 index = 1 開始跑
        for (size_t i = 1; i < events.size(); i++) {
            // event 的時間減 startTime 是現在的時長
            int thisTime = events[i][1] - startTime;
            startTime = events[i][1];

            // 如果現在的時長大於最長的時長, 則更新
            if (thisTime > longestTime) {
                longestTime = thisTime;
                buttonIndex = events[i][0];
            } else if (thisTime == longestTime) {
                // 如果現在的時長和最長的時長相同, 則取小的 index
                buttonIndex = std::min(buttonIndex, events[i][0]);
            }
        }
        
        return buttonIndex;
    }
};