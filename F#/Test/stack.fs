module FSharp.StackTest

open FSharp.Stack
open FsUnit
open NUnit.Framework

let [<Test>] ``the size should be correct`` () =
    let testee = Stack()
    testee.size |> should equal 0
    testee.push 1
    testee.size |> should equal 1

let [<Test>] ``push should be correct`` () =
    let testee = Stack()
    testee.push 1
    testee.peek() |> should equal 1

let [<Test>] ``pop should be correct`` () =
    let testee = Stack()
    testee.push 1
    testee.push 2
    testee.pop() |> should equal 2
    testee.size |> should equal 1

let [<Test>] ``isEmpty should be correct`` () =
    let testee = Stack()
    testee.isEmpty |> should equal true
    testee.push 1
    testee.isEmpty |> should equal false