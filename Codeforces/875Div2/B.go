package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscan(reader, &T)

	for ; T > 0; T-- {

		var (
			N    int
			A, B [200001]int
		)

		fmt.Fscan(reader, &N)
		for i := 1; i <= N; i++ {
			fmt.Fscan(reader, &A[i])
		}
		for i := 1; i <= N; i++ {
			fmt.Fscan(reader, B[i])
		}

		var set map[int]int

		val, strike := 0
		for i := 1; i <= N; i++ {

		}
	}
}
