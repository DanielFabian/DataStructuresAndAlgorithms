let sum_of_n n =
    let mutable sum = 0L
    for i = 1 to n do
        sum <- sum + int64 i
    sum

printfn "Hello World"
printfn "%d" (sum_of_n 10)


for i = 1 to 5 do
    let sw = System.Diagnostics.Stopwatch.StartNew()
    let res = sum_of_n 1000000
    sw.Stop()
    printfn "sum_of_n 10^6 = %d, took %9.7f seconds" res sw.Elapsed.TotalSeconds