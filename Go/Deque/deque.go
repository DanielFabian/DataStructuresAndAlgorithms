package Dequeue
type Deque struct {
    data []interface{}
}

func (d *Deque) size() int {
    return len(d.data)
}

func (d *Deque) addFront(item interface{}) {
    d.data = append([]interface{}{item}, d.data...)
}

func (d *Deque) addRear(item interface{}) {
    d.data = append(d.data, item)
}

func (d *Deque) removeRear() interface{} {
    res := d.data[len(d.data) - 1]
    d.data = d.data[:len(d.data) - 1]
    return res
}

func (d *Deque) removeFront() interface{} {
    res := d.data[0]
    d.data = d.data[1:]
    return res
}

func palchecker(word string) bool {
    deque := new(Deque)
    for _, c := range word {
        deque.addRear(c)
    }

    for deque.size() > 1 {
        if deque.removeFront() != deque.removeRear() {
            return false
        }
    }
    return true
}