module MainTest

open FsUnit
open NUnit.Framework
open Main
open System
open System.Diagnostics

let printBenchmark name elapsed n =
    let averageTime = (elapsed:TimeSpan).TotalMilliseconds / float n * 1000000.0
    match averageTime with
    | short when short < 1000.0 -> printfn "%s, iterations %d, %0.3f ns/op" name n averageTime
    | long -> printfn "%s, iterations %d, %d ns/op" name n (int averageTime)

let [<Test>] test_sum_of_n () =
    sum_of_n 10000 |> should equal 50005000

let [<Test>] performance_sum_of_n () =
    let n = 100
    let sw = Stopwatch.StartNew()
    for i = 1 to n do
        sum_of_n 10000 |> ignore
    sw.Stop()
    
    printBenchmark "sum_of_n" sw.Elapsed n