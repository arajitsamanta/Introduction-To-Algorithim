package main

import (
	"fmt"
	"time"
)

const (
	//MinInt32 - int32 minimum value
	MinInt32 = -1 << 31
	//CutLength identifies which length to cut.
	CutLength = 32
)

func max(a, b int32) int32 {
	if a > b {
		return a
	}
	return b
}

func cutRod(p []int32, n int32) int32 {
	var i, maxInt int32
	if n == 0 {
		return 0
	}

	maxInt = MinInt32

	for i = 0; i < n; i++ {
		maxInt = max(maxInt, p[i]+cutRod(p, n-i-1))
	}
	return maxInt
}

func cutRodMemoized(p []int32, n int32, memo map[int32]int32) int32 {
	var i, maxInt int32

	if v, ok := memo[n]; ok {
		return v
	}

	maxInt = MinInt32

	if n == 0 {
		maxInt = 0
	} else {
		for i = 0; i < n; i++ {
			maxInt = max(maxInt, p[i]+cutRodMemoized(p, n-i-1, memo))
		}
	}
	memo[n] = maxInt
	return maxInt
}

func cutRodBottomUp(p []int32, n int32) int32 {

	var (
		i, j, maxInt int32
		maxRevenue   []int32
	)
	arrSize := n + 1

	maxRevenue = make([]int32, arrSize)

	for i = 0; i < n; i++ {
		maxInt = MinInt32
		for j = 0; j <= i; j++ {
			maxInt = max(maxInt, p[j]+maxRevenue[i-j])
		}
		maxRevenue[i+1] = maxInt
	}
	return maxRevenue[arrSize-1]
}

func main() {
	prices := []int32{1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}
	begin := time.Now()
	fmt.Printf("Recursion: %d Time: %v", cutRod(prices, CutLength), time.Since(begin).Seconds())

	memo := make(map[int32]int32)

	begin = time.Now()
	fmt.Printf("\nMemoized: %d Time: %v", cutRodMemoized(prices, CutLength, memo), time.Since(begin).Seconds())

	begin = time.Now()
	fmt.Printf("\nBottom Up: %d Time: %v", cutRodBottomUp(prices, CutLength), time.Since(begin).Seconds())
	fmt.Println()

}
