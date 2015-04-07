package Dequeue;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

/**
 * Created by Daniel on 4/5/2015.
 */
public class DequeueTest {

    @Test
    public void testSize() throws Exception {
        Dequeue<Integer> testee = new Dequeue<Integer>();
        assertEquals(0, testee.size());

        testee.addFront(1);

        assertEquals(1, testee.size());
    }

    @Test
    public void testAddFront() throws Exception {
        Dequeue<Integer> testee = new Dequeue<Integer>();
        testee.addFront(1);
        testee.addFront(2);
        testee.addFront(3);
        assertEquals(new Integer(1), testee.removeRear());
    }

    @Test
    public void testAddRear() throws Exception {
        Dequeue<Integer> testee = new Dequeue<Integer>();
        testee.addRear(1);
        testee.addRear(2);
        testee.addRear(3);
        assertEquals(new Integer(3), testee.removeRear());
    }

    @Test
    public void testRemoveFront() throws Exception {
        Dequeue<Integer> testee = new Dequeue<Integer>();
        testee.addRear(1);
        testee.addRear(2);
        testee.addRear(3);
        assertEquals(new Integer(1), testee.removeFront());
        assertEquals(new Integer(2), testee.removeFront());
        assertEquals(new Integer(3), testee.removeFront());
        assertEquals(0, testee.size());
    }
}
