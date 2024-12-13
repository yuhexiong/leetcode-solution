// Problem 359: Logger Rate Limiter
// https://leetcode.com/problems/string-compression-iii/

#include <string>
#include <unordered_map>
using namespace std;

class Logger {
public:
    // 初始化 timestampDict 為空的 map
    unordered_map<string, int> timestampDict;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // 如果在 timestampDict 內找不到 message, 就紀錄為 timestamp + 10 並回傳 true
        if (timestampDict.find(message) == timestampDict.end()) {
            timestampDict[message] = timestamp + 10;
            return true;
        } else {
            // 如果在 timestampDict 內找得到 message, 取出後比較，小於就回傳 false，其他則更新為新的 timestamp + 10 並回傳 true
            int allowedTimestamp = timestampDict[message];
            if (timestamp < allowedTimestamp) {
                return false;
            } else {
                timestampDict[message] = timestamp + 10;
                return true;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */