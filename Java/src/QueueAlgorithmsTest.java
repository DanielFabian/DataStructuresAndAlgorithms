import org.junit.Test;

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
}
