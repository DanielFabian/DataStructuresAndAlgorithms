package Go
import "testing"

func Test_size(t *testing.T) {
    testee := new(Stack)
    if testee.size() != 0 {
        t.Errorf("size of empty stack should be 0");
    }
}