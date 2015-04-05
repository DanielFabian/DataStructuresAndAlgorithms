module FSharp.Queue


/// bad implementation of a queue with O(n) dequeue
type Queue<'T>() =
    let data = ResizeArray<'T>()
    member this.size = data.Count
    member this.enqueue item = data.Add item
    member this.dequeue() =
        let res = data.[0]
        data.RemoveAt 0
        res
    member this.isEmpty = data.Count = 0