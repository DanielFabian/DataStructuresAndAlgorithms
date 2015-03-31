package Go

type Stack struct  {
    data []interface{}
}

func (s *Stack) size() {
    return len(s.data)
}