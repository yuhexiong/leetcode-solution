// Problem 3263: Convert Doubly Linked List to Array I
// https://leetcode.com/problems/convert-doubly-linked-list-to-array-i/

package Go

//lint:file-ignore U1000 Ignore all unused code
// Definition for a Node.
type Node struct {
	Val  int
	Next *Node
	Prev *Node
}

func toArray(head *Node) []int {
	ans := []int{}
	for head != nil {
		ans = append(ans, head.Val)
		head = head.Next
	}
	return ans
}
