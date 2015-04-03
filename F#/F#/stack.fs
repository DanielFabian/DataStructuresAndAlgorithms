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

let toBase b num =
    let digits = Array.append [|'0'..'9'|] [|'A'..'Z'|]
    let stack = Stack()
    let rec consume = function
        | 0 -> ()
        | n -> stack.push digits.[n % b]; consume (n / b)
    
    consume num

    let rec buildString str =
        if stack.isEmpty then str
        else buildString (str + stack.pop().ToString())

    buildString ""

let toBinary = toBase 2

let toPostfix str =
    let tokens = (str : string).Split ' '
    let operators = Stack()
    let res = ResizeArray()

    let prec =
        function
        | "+" | "-" -> 1
        | "*" | "/" -> 2
        | _ -> 0

    tokens
    |> Array.iter(
        function
        | "(" -> operators.push "("
        | ")" ->
            let rec loop op =
                if op <> "(" then
                    res.Add op
                    loop <| operators.pop()

            loop <| operators.pop()
        | "+" | "-" | "*" | "/" as op -> 
            while not operators.isEmpty && prec op <= prec (operators.peek()) do
                res.Add (operators.pop())
            operators.push op          
        | operand -> res.Add operand)

    while not operators.isEmpty do
        res.Add(operators.pop())

    String.concat " " res


let evalPostfix str = 
    let tokens = (str:string).Split ' ' 
    let evalStack = Stack()

    let eval (++) =
        let right = evalStack.pop()
        let left = evalStack.pop()
        evalStack.push(left ++ right)

    tokens
    |> Array.iter(
        function
        | "+" -> eval (+)
        | "-" -> eval (-)
        | "*" -> eval (*)
        | "/" -> eval (/)
        | token -> evalStack.push(System.Int32.Parse token))
    
    evalStack.pop()









