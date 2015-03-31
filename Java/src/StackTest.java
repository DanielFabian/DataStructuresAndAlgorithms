import junit.framework.TestCase;

/**
 * Created by Daniel on 31.03.2015.
 */
public class StackTest extends TestCase {

    public void testIsEmpty() throws Exception {
        Stack<Integer> testee = new Stack<>();
        assertTrue(testee.isEmpty());

        testee.push(1);

        assertFalse(testee.isEmpty());
    }

    public void testSize() throws Exception {
        Stack<Integer> testee = new Stack<>();

        assertEquals(testee.size(), 0);

        testee.push(1);
        testee.push(2);

        assertEquals(testee.size(), 2);
    }

    public void testPush() throws Exception {
        Stack<Integer> testee = new Stack<>();
        testee.push(1);
        assertEquals(testee.peek(), new Integer(1));
        testee.push(2);
        assertEquals(testee.peek(), new Integer(2));
        testee.push(3);
        assertEquals(testee.peek(), new Integer(3));
        assertEquals(testee.size(), 3);
    }

    public void testPop() throws Exception {
        Stack<Integer> testee = new Stack<>();
        testee.push(1);
        testee.push(2);
        testee.push(3);
        assertEquals(testee.size(), 3);
        assertEquals(testee.pop(), new Integer(3));
        assertEquals(testee.size(), 2);
    }
}