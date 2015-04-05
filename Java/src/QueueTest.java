import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Daniel on 4/5/2015.
 */
public class QueueTest {

    @Test
    public void testIsEmpty() throws Exception {
        Queue<Integer> testee = new Queue<>();
        assertTrue(testee.isEmpty());

        testee.enqueue(1);

        assertFalse(testee.isEmpty());
    }

    @Test
    public void testSize() throws Exception {
        Queue<Integer> testee = new Queue<>();

        assertEquals(0, testee.size());

        testee.enqueue(1);
        testee.enqueue(2);

        assertEquals(2, testee.size());
    }

    @Test
    public void testEnqueue() throws Exception {
        Queue<Integer> testee = new Queue<>();
        testee.enqueue(1);
        testee.enqueue(2);
        testee.enqueue(3);
        assertEquals(3, testee.size());
    }

    @Test
    public void testDequeue() throws Exception {
        Queue<Integer> testee = new Queue<>();
        testee.enqueue(1);
        testee.enqueue(2);
        testee.enqueue(3);
        assertEquals(3, testee.size());
        assertEquals(new Integer(1), testee.dequeue());
        assertEquals(2, testee.size());
    }
}
