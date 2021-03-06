package Queue
import "testing"

func Test_size(t *testing.T) {
    testee := new(Queue)
    if testee.size() != 0 {
        t.Errorf("size of empty queue should be 0")
    }
    testee.enqueue(1)
    if testee.size() != 1 {
        t.Errorf("size after one enqueue, should be 1")
    }
}

func Test_enqueue(t *testing.T) {
    testee := new(Queue)
    testee.enqueue(1)

    if testee.dequeue() != 1 {
        t.Errorf("the first item should be read properly")
    }
}

func Test_dequeue(t *testing.T) {
    testee := new(Queue)
    testee.enqueue(1)
    testee.enqueue(2)
    res := testee.dequeue()

    if res != 1 {
        t.Errorf("the dequeueped item should be the same as the one put in")
    }

    if testee.size() != 1 {
        t.Errorf("after removing, the queue should have length 1")
    }
}

func Test_isEmpty(t *testing.T) {
    testee := new(Queue)
    if testee.isEmpty() != true {
        t.Errorf("An initial queue is empty")
    }

    testee.enqueue(1)

    if testee.isEmpty() {
        t.Errorf("After enqueueing the queue is no longer empty")
    }
}

func Test_hotPotato(t *testing.T) {
    res := hotPotato([]string{"Bill","David","Susan","Jane","Kent","Brad"}, 7)
    if res != "Susan" {
        t.Errorf("hotPotato was %s, expected Susan", res)
    }
}

func Test_printQueue(t *testing.T) {
    print("\n")
    for i := 0; i < 10; i++ {
        printQueue(3600, 5)
    }
}