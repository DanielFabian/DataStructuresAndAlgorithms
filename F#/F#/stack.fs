module FSharp.Stack

type Stack<'T>() =
    let data = ResizeArray<'T>()

    member this.isEmpty = data.Count = 0
    member this.push item = data.Add item
    member this.peek () = data.[data.Count - 1]
    member this.pop () =
        let idx = data.Count - 1
        let res = data.[idx]
        data.RemoveAt idx
        res
    member this.size = data.Count

let checkParentheses str =
    let stack = Stack()
    str
    |> String.forall(fun c ->
        if c = ')' || c = ']' || c = '}' || c = '>' then
            not stack.isEmpty && stack.pop() = c
        else
            if c = '(' then stack.push ')'
            if c = '[' then stack.push ']'
            if c = '{' then stack.push '}'
            if c = '<' then stack.push '>'
            true
    ) && stack.isEmpty