package main
import (
    "fmt"
    "time"
)

func main() {
    fmt.Println("Hello World")

    fmt.Println(sum_of_n(10))

    for i := 1; i <= 5; i++ {
        var start = time.Now()
        res := int64(0)
        for i := 0; i < 100; i++ {
           res = sum_of_n(1000000)

        }
        var stop = time.Now()
        fmt.Printf("sum_of_n 10^6 = %d, took %9.7f seconds\n", res, stop.Sub(start).Seconds()/100.0)
    }
}

func sum_of_n(n int64) int64 {
    var res = int64(0)
    for i := int64(1); i <= n; i++  {
        res += i
    }

    return res
}