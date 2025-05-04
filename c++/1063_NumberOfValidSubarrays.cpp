// Problem 1063: Number of Valid Subarrays
// https://leetcode.com/problems/number-of-valid-subarrays/

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int validSubarrays(vector<int> &nums)
    {
        stack<int> stk;
        int cnt = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            // stack 為小於目前為止右邊所有數的數值, 可以做為左端點
            // 如果 num 小於 stack 後面的值就要移除 num 直到大於等於 stack
            while (!stk.empty() && num < stk.top())
            {
                stk.pop();
            }
            // 將 num 加入 stack
            stk.push(num);
            // stk.size() 代表當 num 為最右端點時, 有效的左端點數量
            cnt += stk.size();
        }

        return cnt;
    }
};