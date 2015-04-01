import java.util.ArrayList;

/**
 * Created by Daniel on 31.03.2015.
 */
public class Stack<T> {
    private final ArrayList<T> items;

    public Stack() {
        this.items = new ArrayList<>();
    }

    public boolean isEmpty()
    {
        return items.isEmpty();
    }

    public int size()
    {
        return items.size();
    }

    public void push(T item)
    {
        items.add(item);
    }

    public T peek()
    {
        return items.get(items.size() - 1);
    }

    public T pop()
    {
        int idx = items.size() - 1;
        T res = items.get(idx);
        items.remove(idx);
        return res;
    }
}
