import org.junit.Test;
import static org.junit.Assert.*;

/**
 * Created by Daniel on 31.03.2015.
 */
public class StackTest {

    @Test
    public void testIsEmpty() throws Exception {
        Stack<Integer> testee = new Stack<>();
        assertTrue(testee.isEmpty());

        testee.push(1);

        assertFalse(testee.isEmpty());
    }

    @Test
    public void testSize() throws Exception {
        Stack<Integer> testee = new Stack<>();

        assertEquals(0, testee.size());

        testee.push(1);
        testee.push(2);

        assertEquals(2, testee.size());
    }

    @Test
    public void testPush() throws Exception {
        Stack<Integer> testee = new Stack<>();
        testee.push(1);
        assertEquals(new Integer(1), testee.peek());
        testee.push(2);
        assertEquals(new Integer(2), testee.peek());
        testee.push(3);
        assertEquals(new Integer(3), testee.peek());
        assertEquals(3, testee.size());
    }

    @Test
    public void testPop() throws Exception {
        Stack<Integer> testee = new Stack<>();
        testee.push(1);
        testee.push(2);
        testee.push(3);
        assertEquals(3, testee.size());
        assertEquals(new Integer(3), testee.pop());
        assertEquals(2, testee.size());
    }
}