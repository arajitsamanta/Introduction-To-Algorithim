package main

import (
	"fmt"
)

type node struct {
	left  *node
	data  int
	right *node
}

//Create a new tree node with value as v and left,right as null
func new(v int) *node {
	return &node{nil, v, nil}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func depth(root *node) int {
	if root == nil {
		return 0
	}
	return 1 + max(depth(root.left), depth(root.right))
}

func height(root *node) int {
	if root == nil {
		return -1
	}
	return 1 + max(height(root.left), height(root.right))
}

func main() {

	//Level 0 - root
	root := new(1)

	//Level 1 - left and right
	root.left = new(2)
	root.left = new(3)

	//Level 2 - left.left and left.right
	root.left.left = new(4)
	root.left.right = new(5)

	//Max depth of a node
	fmt.Printf("Depth: %d Height %d", depth(root), height(root))

}
