/**
 * Created by Daniel on 05.04.2015.
 */
public class QueueAlgorithms {
    public static String hotPotato(String[] names, int num) {
        Queue<String> queue = new Queue<>();
        for (String name : names) {
            queue.enqueue(name);
        }

        while (queue.size() > 1) {
            for (int i = 0; i < num; i++) {
                queue.enqueue(queue.dequeue());
            }

            queue.dequeue();
        }

        return queue.dequeue();
    }
}
