package Queue

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