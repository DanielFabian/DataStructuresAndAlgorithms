package Dequeue
import "testing"

func Test_size(t *testing.T) {
    testee := new(Deque)
    if testee.size() != 0 {
        t.Errorf("size of empty dequeue should be 0")
    }
    testee.addFront(1)
    if testee.size() != 1 {
        t.Errorf("size after one addFront, should be 1")
    }
}

func Test_addFront(t *testing.T) {
    testee := new(Deque)
    testee.addFront(1)
    testee.addFront(2)
    testee.addFront(3)

    if testee.removeRear() != 1 {
        t.Errorf("the first item should be read properly")
    }
}

func Test_addRear(t *testing.T) {
    testee := new(Deque)
    testee.addRear(1)
    testee.addRear(2)
    testee.addRear(3)

    if testee.size() != 3 || testee.removeRear() != 3 {
        t.Errorf("the last item should be read properly")
    }
}

func Test_removeFront(t *testing.T) {
    testee := new(Deque)
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

func Test_removeRear(t *testing.T) {
    testee := new(Deque)
    testee.addRear('x')
    testee.addRear('y')

    x := testee.removeFront()
    y := testee.removeRear()
    if !(x == 'x' && y == 'y') {
        t.Fail()
    }
}

func Test_palchecker(t *testing.T) {
    tests := []struct { exp bool; inp string }{
        {false, "xy"},
        {false, "lsdkjfskf"},
        {true, "radar"},
    }

    for _, test := range tests {
        actual := palchecker(test.inp)
        if actual != test.exp {
            t.Errorf("palchecker(\"%s\") = %t, expected %t", test.inp, actual, test.exp)
        }
    }
}