// Problem 3324: Find the Sequence of Strings Appeared on the Screen
// https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/

package Go

//lint:file-ignore U1000 Ignore all unused code
func stringSequence(target string) []string {
	// 宣告空陣列為答案
	var sequence []string

	// 預設開始的字是空字串
	currWord := ""

	// 跑迴圈看每個字元
	for _, t := range target {
		// 預設從 a 的前一個編碼開始
		currLetter := 'a' - 1

		// 如果目前字母的編碼數小於目標則繼續, 持續 + 1 且加入答案陣列, 到等於時會跳脫迴圈
		for currLetter < t {
			currLetter++
			sequence = append(sequence, currWord+string(currLetter))
		}
		// 字母確定為目標後加入目前字串
		currWord += string(currLetter)
	}

	// 回傳答案
	return sequence
}
