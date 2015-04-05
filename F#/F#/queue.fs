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


let rng = System.Random()

type Task(time) =
    let timestamp = time
    let pages = rng.Next(1, 21)

    member this.Stamp = timestamp
    member this.Pages = pages
    member this.WaitTime currenttime = currenttime - timestamp
    
type Printer(ppm) =
    let pagerate = ppm
    let mutable currentTask = None
    let mutable timeRemaining = 0

    member this.Tick() =
        currentTask
        |> Option.iter (fun task ->
            timeRemaining <- timeRemaining - 1
            if timeRemaining <= 0 then
                currentTask <- None
                
        ) 

    member this.Busy =
        Option.isSome currentTask

    member this.StartNext (task:Task) =
        currentTask <- Some task
        timeRemaining <- task.Pages * 60 / pagerate

let printQueue(numSeconds, pagesPerMinute) =
    let labprinter = Printer(pagesPerMinute)
    let printQueue = Queue()
    let waitingtimes = ResizeArray()

    let newPrintTask() =
        rng.Next(1, 181) = 180

    for currentSecond = 0 to numSeconds - 1 do
        if newPrintTask() then
            printQueue.enqueue(Task(currentSecond))

        if not labprinter.Busy && not (printQueue.isEmpty) then
            let nexttask = printQueue.dequeue()
            waitingtimes.Add(nexttask.WaitTime currentSecond)
            labprinter.StartNext nexttask

        labprinter.Tick()

    printfn "average wait: %6.2f seconds %3d tasks remaining." (Seq.averageBy float waitingtimes) printQueue.size