﻿module FSharp.StackTest

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

let [<Test>] checkParentheses() =
    let tests =
        [
            true, "() [] () ([]()[])"
            true, "(()()()())"
            true, "(()((())()))"
            true, @"#pragma once
#include <vector>
#include <cstdlib>

template <class T>
class stack {
private:
    std::vector<T> data;
public:
    void push(const T& item);
    T pop();
    T peek();
    bool isEmpty();
    size_t size();
};"
            false, "( (] ([)]"
            false, "((((((())"
            false, "()))"
            false, "(()()(()"
        ]

    tests
    |> List.iter (fun (expected, input) ->
        checkParentheses input |> should equal expected)

let [<Test>] toBinary () =
    233 |> toBinary |> should equal "11101001"
    
let [<Test>] toBase () =
    233 |> toBase 2 |> should equal "11101001"
    233 |> toBase 8 |> should equal "351"
    233 |> toBase 16 |> should equal "E9"
    
let [<Test>] toPostfix () =
    "( A + B ) * ( C + D )" |> toPostfix |> should equal "A B + C D + *"
    "( A + B ) * C" |> toPostfix |> should equal "A B + C *"
    "A + B * C" |> toPostfix |> should equal "A B C * +"

let [<Test>] evalPostfix () =
    "7 8 + 3 2 + /" |> evalPostfix |> should equal 3
    "17 10 + 3 * 9 /" |> evalPostfix |> should equal 9
    "5 1 2 + 4 * + 3 -" |> evalPostfix |> should equal 14
    "3 4 + 5 *" |> evalPostfix |> should equal 35
    "1 2 + 3 4 + *" |> evalPostfix |> should equal 21