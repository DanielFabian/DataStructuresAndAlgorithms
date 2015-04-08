module FSharp.Deque

type Deque<'T>() =
    let data = ResizeArray<'T>()
    
    member this.addFront item = 
        data.Insert(0, item)
    
    member this.addRear item =
        data.Add item
    
    member this.removeRear () = 
        let res = data.[data.Count - 1]
        data.RemoveAt(data.Count - 1)
        res

    member this.removeFront () =
        let res = data.[0]
        data.RemoveAt(0)
        res
    
    member this.size () = data.Count


let palchecker word =
    let deque = Deque()
    word |> Seq.iter deque.addRear

    let rec loop () =
        if deque.size() > 1 then
            if deque.removeFront() <> deque.removeRear() then
                false
            else loop ()
        else true

    loop ()