// Problem 3259: Maximum Energy Boost From Two Drinks
// https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/

package Go

//lint:file-ignore U1000 Ignore all unused code
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
	// 從倒數第二個開始往前跑
	// 如果是倒數第二個, 選擇就只有自己這個 list 的最後一個
	// 如果是倒數第二個以前, 選擇就有自己這個 list 的下一個 或 另外一個 list 的下下一個
	// 利用由後往前算來把之後所有可能的最大值加在自己這個值上, 最後 index = 0 的位置的值就是最好的選擇
	for i := len(energyDrinkA) - 2; i >= 0; i-- {
		if i >= len(energyDrinkA)-2 {
			energyDrinkA[i] += energyDrinkA[i+1]
			energyDrinkB[i] += energyDrinkB[i+1]
		} else {
			energyDrinkA[i] += max(energyDrinkA[i+1], energyDrinkB[i+2])
			energyDrinkB[i] += max(energyDrinkB[i+1], energyDrinkA[i+2])
		}
	}

	return int64(max(energyDrinkA[0], energyDrinkB[0]))
}
