import Deque.DequeAlgorithms;
import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

/**
 * Created by Daniel on 08.04.2015.
 */
public class DequeAlgorithmsTest {
    @Test
    public void testPalchecker() throws Exception {
        assertFalse(DequeAlgorithms.palchecker("lsdkjfskf"));
        assertTrue(DequeAlgorithms.palchecker("radar"));
    }
}
