module FSharp.Queue

open FSharp.Queue
open FsUnit
open NUnit.Framework

let [<Test>] ``the size should be correct`` () =
    let testee = Queue()
    testee.size |> should equal 0
    testee.enqueue 1
    testee.size |> should equal 1

let [<Test>] ``enqueue should be correct`` () =
    let testee = Queue()
    testee.enqueue 1
    testee.dequeue() |> should equal 1

let [<Test>] ``dequeue should be correct`` () =
    let testee = Queue()
    testee.enqueue 1
    testee.enqueue 2
    testee.dequeue() |> should equal 1
    testee.size |> should equal 1

let [<Test>] ``isEmpty should be correct`` () =
    let testee = Queue()
    testee.isEmpty |> should equal true
    testee.enqueue 1
    testee.isEmpty |> should equal false


let [<Test>] hotPotato () =
    hotPotato ["Bill";"David";"Susan";"Jane";"Kent";"Brad"] 7 |> should equal "Susan"