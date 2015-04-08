module FSharp.DequeTest

open FsUnit
open FSharp.Deque
open NUnit.Framework

let [<Test>] size () =
    let deque = Deque()

    deque.size() |> should equal 0
    
    deque.addFront 1

    deque.size() |> should equal 1


let [<Test>] addFront () =
    let deque = Deque()

    deque.addFront 1
    deque.addFront 2
    deque.addFront 3

    deque.removeRear() |> should equal 1


let [<Test>] addRear () =
    let deque = Deque()

    deque.addRear 1
    deque.addRear 2
    deque.addRear 3

    deque.removeRear() |> should equal 3


let [<Test>] removeFront () =
    let deque = Deque()

    deque.addRear 1
    deque.addRear 2
    deque.addRear 3

    deque.removeFront() |> should equal 1
    deque.removeFront() |> should equal 2
    deque.removeFront() |> should equal 3
    deque.size() |> should equal 0


let [<Test>] palchecker() =
    palchecker "lsdkjfskf" |> should equal false
    palchecker "radar" |> should equal true