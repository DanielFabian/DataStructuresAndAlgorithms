package Dequeue


type Dequeue struct {
    data []interface{}
}

func (d *Dequeue) size() int {
    return len(d.data)
}

func (d *Dequeue) addFront(item interface{}) {
    d.data = append([]interface{}{item}, d.data...)
}

func (d *Dequeue) addRear(item interface{}) {
    d.data = append(d.data, item)
}

func (d *Dequeue) removeRear() interface{} {
    res := d.data[len(d.data) - 1]
    d.data = d.data[0:len(d.data) - 2]
    return res
}

func (d *Dequeue) removeFront() interface{} {
    res := d.data[0]
    d.data = d.data[1:]
    return res
}