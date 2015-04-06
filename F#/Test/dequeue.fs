module FSharp.DequeueTest

open FsUnit
open FSharp.Dequeue
open NUnit.Framework

let [<Test>] size () =
    let dequeue = Dequeue()

    dequeue.size() |> should equal 0
    
    dequeue.addFront 1

    dequeue.size() |> should equal 1


let [<Test>] addFront () =
    let dequeue = Dequeue()

    dequeue.addFront 1
    dequeue.addFront 2
    dequeue.addFront 3

    dequeue.removeRear() |> should equal 1


let [<Test>] addRear () =
    let dequeue = Dequeue()

    dequeue.addRear 1
    dequeue.addRear 2
    dequeue.addRear 3

    dequeue.removeRear() |> should equal 3


let [<Test>] removeFront () =
    let dequeue = Dequeue()

    dequeue.addRear 1
    dequeue.addRear 2
    dequeue.addRear 3

    dequeue.removeFront() |> should equal 1
    dequeue.removeFront() |> should equal 2
    dequeue.removeFront() |> should equal 3
    dequeue.size() |> should equal 0
