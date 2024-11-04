// Problem 3340: Check Balanced String
// https://leetcode.com/problems/check-balanced-string/

package Go

import "strconv"

//lint:file-ignore U1000 Ignore all unused code
func isBalanced(num string) bool {
	// 宣告奇數總和、偶數總和兩個變數為 0
	odd_sum := 0
	even_sum := 0

	// 跑迴圈將每個位數都轉換成數字, 並依據 index 為奇數或偶數加入總和
	for i, digit := range num {
		intDigit, _ := strconv.Atoi(string(digit))

		if i%2 == 0 {
			even_sum += intDigit
		} else {
			odd_sum += intDigit
		}
	}

	// 回傳奇數總和是否等於偶數總和
	return odd_sum == even_sum
}
