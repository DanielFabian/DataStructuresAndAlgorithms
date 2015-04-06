module FSharp.Dequeue

type Dequeue<'T>() =
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

