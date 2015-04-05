package Queue;

import java.util.ArrayList;

/**
 * Created by Daniel on 4/5/2015.
 * Bad implementation of a queue with O(n) dequeue.
 */
public class Queue<T> {
    private final ArrayList<T> data;

    public Queue() {
        this.data = new ArrayList<>();
    }

    public boolean isEmpty(){
        return data.isEmpty();
    }

    public void enqueue(T i) {
        data.add(i);
    }

    public int size() {
        return data.size();
    }

    public T dequeue() {
        T res = data.get(0);
        data.remove(0);
        return res;
    }
}
