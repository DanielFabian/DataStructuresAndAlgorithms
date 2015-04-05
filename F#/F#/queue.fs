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

let hotPotato names num =
    let queue = Queue()
    List.iter queue.enqueue names

    while queue.size > 1 do
        for i = 1 to num do
            queue.enqueue(queue.dequeue())
        queue.dequeue() |> ignore

    queue.dequeue()