package Dequeue
import "testing"




func Test_size(t *testing.T) {
    testee := new(Dequeue)
    if testee.size() != 0 {
        t.Errorf("size of empty dequeue should be 0")
    }
    testee.addFront(1)
    if testee.size() != 1 {
        t.Errorf("size after one addFront, should be 1")
    }
}

func Test_addFront(t *testing.T) {
    testee := new(Dequeue)
    testee.addFront(1)
    testee.addFront(2)
    testee.addFront(3)

    if testee.removeRear() != 1 {
        t.Errorf("the first item should be read properly")
    }
}

func Test_addRear(t *testing.T) {
    testee := new(Dequeue)
    testee.addRear(1)
    testee.addRear(2)
    testee.addRear(3)

    if testee.removeRear() != 3 {
        t.Errorf("the last item should be read properly")
    }
}

func Test_removeFront(t *testing.T) {
    testee := new(Dequeue)
    testee.addRear(1)
    testee.addRear(2)
    testee.addRear(3)

    if testee.removeFront() != 1 {
        t.Errorf("the first item should be the same as the one put in")
    }

    if testee.removeFront() != 2 {
        t.Errorf("the second item should be the same as the one put in")
    }

    if testee.removeFront() != 3 {
        t.Errorf("the third item should be the same as the one put in")
    }

    if testee.size() != 0 {
        t.Errorf("after removing all items, the dequeue should have length 1")
    }
}