package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	T int
	N int
	A [101]int64
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &T)

	for ; T > 0; T-- {

		fmt.Fscan(reader, &N)

		for i := 1; i <= N; i++ {
			fmt.Fscan(reader, &A[i])
			fmt.Fprint(writer, int64(N+1)-A[i], " ")
		}
		fmt.Fprint(writer, "\n")
	}
}
