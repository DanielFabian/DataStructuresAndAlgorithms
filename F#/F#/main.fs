module FSharp.Main

let sum_of_n n =
    let mutable sum = 0L
    for i = 1 to n do
        sum <- sum + int64 i
    sum

printfn "Hello World"
printfn "%d" (sum_of_n 10)
