package Queue;

import org.junit.Test;

import java.util.Random;

import static org.junit.Assert.assertEquals;

/**
 * Created by Daniel on 05.04.2015.
 */
public class QueueAlgorithmsTest {
    @Test
    public void testHotPotato() throws Exception {
        String[] names = new String[]{"Bill", "David", "Susan", "Jane", "Kent", "Brad"};
        assertEquals("Susan", QueueAlgorithms.hotPotato(names, 7));

    }

    @Test
    public void testPrintQueue() throws Exception {
        Random rng = new Random();
        for (int i = 0; i < 10; i++) {
            QueueAlgorithms.PrinterQueue(rng, 3600, 5);
        }
    }
}
