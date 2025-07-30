# Problem 3622: Check Divisibility by Digit Sum and Product
# https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/

class Solution:
    def check_divisibility(self, n: int) -> bool:
        # 初始化加總為 0, 乘積為 1
        digit_sum = 0
        digit_product = 1

        # 設定一個暫時的 n 跑迴圈進行拆解
        tmp_n = n
        while tmp_n > 0:
            # 取出最後一個位數進行加總或加乘
            digit_sum += tmp_n % 10
            digit_product *= tmp_n % 10
            # 將 tmp_n 除以 10 以在下一個只取得十位數前的數字
            tmp_n //= 10

        # 依照題意回傳驗證結果
        return n % (digit_sum + digit_product) == 0