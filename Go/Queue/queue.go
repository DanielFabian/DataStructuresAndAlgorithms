package Queue
import (
    "fmt"
    "math/rand"
)

// bad implementation of a queue with linearly growing memory consumption.
type Queue struct {
    data []interface{}
}

func (q *Queue) size() int {
    return len(q.data)
}

func (q *Queue) enqueue(item interface{}) {
    q.data = append(q.data, item)
}

func (q *Queue) dequeue() interface{} {
    res := q.data[0];
    q.data = q.data[1:]
    return res
}

func (q *Queue) isEmpty() bool {
    return len(q.data) == 0
}

func hotPotato(names []string, num int) string {
    queue := new(Queue)
    for _, name := range names {
        queue.enqueue(name)
    }

    for queue.size() > 1 {
        for i := 0; i < num; i++ {
            queue.enqueue(queue.dequeue())
        }

        queue.dequeue()
    }

    return queue.dequeue().(string)
}

type Task struct {
    timestamp, pages int
}

func NewTask(timestamp int) Task {
    return Task{timestamp, rand.Intn(20) + 1}
}

func (t *Task) TimeStamp() int {
    return t.timestamp
}

func (t *Task) Pages() int {
    return t.pages
}

func (t *Task) WaitTime(currentTime int) int {
    return currentTime - t.timestamp
}

type Printer struct {
    pageRate, timeRemaining int
    currentTask *Task
}

func NewPrinter(ppm int) *Printer {
    res := new(Printer)
    res.pageRate = ppm
    return res
}

func (p *Printer) Tick() {
    if p.currentTask != nil {
        p.timeRemaining--
        if p.timeRemaining <= 0 {
            p.currentTask = nil
        }
    }
}

func (p *Printer) Busy() bool {
    return p.currentTask != nil
}

func (p *Printer) StartNext(task Task) {
    p.currentTask = &task
    p.timeRemaining = task.pages * 60 / p.pageRate
}

func printQueue(numSeconds int, pagesPerMinute int) {
    labPrinter := NewPrinter(pagesPerMinute)
    printerQueue := new(Queue)
    waitingTimes := []int {}

    newPrintTask := func () bool {
        return rand.Intn(180) + 1 == 180
    }

    for currentSecond := 0; currentSecond < numSeconds; currentSecond++ {
        if newPrintTask() {
            printerQueue.enqueue(NewTask(currentSecond))
        }

        if !labPrinter.Busy() && !printerQueue.isEmpty() {
            nextTask := printerQueue.dequeue().(Task)
            waitingTimes = append(waitingTimes, nextTask.WaitTime(currentSecond))
            labPrinter.StartNext(nextTask)
        }

        labPrinter.Tick()
    }

    avg := 0.0
    for _, wt := range waitingTimes {
        avg += float64(wt)
    }

    avg /= float64(len(waitingTimes))

    fmt.Printf("average wait: %6.2f seconds %3d tasks remaining.\n", avg, printerQueue.size())
}