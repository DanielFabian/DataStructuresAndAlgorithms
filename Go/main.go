package main
import (
    "fmt"
)

func main() {
    fmt.Println("Hello World")

    fmt.Println(sum_of_n(10))
}

func sum_of_n(n int) int {
    var res = 0
    for i := 1; i <= n; i++  {
        res += i
    }

    return res
}