package Deque;

/**
 * Created by Daniel on 08.04.2015.
 */
public class DequeAlgorithms {
    public static boolean palchecker(String word) {
        Deque<Character> deque = new Deque<Character>();

        for (char c : word.toCharArray()) {
            deque.addRear(c);
        }

        while (deque.size() > 1) {
            if (!deque.removeFront().equals(deque.removeRear())) {
                return false;
            }
        }

        return true;
    }
}
