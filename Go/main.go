package main
import (
    "fmt"
)

func main() {
    fmt.Println("Hello World")

    fmt.Println(sum_of_n(10))
}

func sum_of_n(n int64) int64 {
    var res = int64(0)
    for i := int64(1); i <= n; i++  {
        res += i
    }

    return res
}