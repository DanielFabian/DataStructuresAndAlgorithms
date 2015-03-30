package main

import (
    "testing"
)

func Test_sum_of_n (t *testing.T) {
    cases := []struct {
        in, want int64
    }{
        { 1, 1 },
        { 10, 55 },
        { 0, 0 },
    }

    for _, c := range cases {
        got := sum_of_n(c.in)
        if got != c.want {
            t.Errorf("sum_of_n(%d) == %d, want %d", c.in, got, c.want)
        }
    }
}

func Benchmark_sum_of_n (b *testing.B) {
    for i := 0; i <  b.N; i++ {
        sum_of_n(10000)
    }
}