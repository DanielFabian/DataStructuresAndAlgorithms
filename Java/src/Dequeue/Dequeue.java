package Dequeue;

import java.util.ArrayList;

/**
 * Created by Daniel on 07.04.2015.
 */
public class Dequeue<T> {
    private final ArrayList<T> data = new ArrayList<>();
    public int size() {
        return data.size();
    }

    public void addFront(T item) {
        data.add(0, item);
    }

    public T removeRear() {
        return data.remove(data.size() - 1);
    }

    public void addRear(T item) {
        data.add(item);
    }

    public T removeFront() {
        return data.remove(0);
    }
}
