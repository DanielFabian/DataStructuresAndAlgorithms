import com.google.common.base.Stopwatch;
import org.junit.Test;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import static org.junit.Assert.assertEquals;

/**
 * Created by Daniel on 30.03.2015.
 */
public class mainTest {

    @Test
    public void test_sum_of_n() throws Exception {
        assertEquals(55, main.sum_of_n(10));
    }

    @Test
    public void benchmark_sum_of_n() {
        int n = 100;
        Stopwatch sw = Stopwatch.createStarted();
        for (int i = 0; i < n; i++) {
            main.sum_of_n(10000);
        }
        sw.stop();

        printBenchmark("sum_of_n", sw.elapsed(TimeUnit.NANOSECONDS), n);
    }

    private static void printBenchmark(String name, long nanoseconds, int n) {
        double averageTime = nanoseconds / (double) n;
        if (averageTime < 1000) {
            System.out.printf("%s, iterations %d, %0.3f ns/op", name, n, averageTime);
        } else {
            System.out.printf("%s, iterations %d, %d ns/op", name, n, (int) averageTime);
        }
    }

    @Test
    public void testCheckParentheses() throws Exception {
        ArrayList<Boolean> expected = new ArrayList<>();
        ArrayList<String> input = new ArrayList<>();
        expected.add(true);
        input.add("() [] () ([]()[])");
        expected.add(true);
        input.add("(()()()())");
        expected.add(true);
        input.add("(()((())()))");
        expected.add(true);
        input.add(
                "#pragma once\n" +
                        "#include <vector>\n" +
                        "#include <cstdlib>\n" +
                        "\n" +
                        "template <class T>\n" +
                        "class stack {\n" +
                        "    private:\n" +
                        "        std::vector<T> data;\n" +
                        "    public:\n" +
                        "        void push(const T& item);\n" +
                        "        T pop();\n" +
                        "        T peek();\n" +
                        "        bool isEmpty();\n" +
                        "        size_t size();\n" +
                        "};\n");
        expected.add(false);
        input.add("( (] ([)]");
        expected.add(false);
        input.add("((((((())");
        expected.add(false);
        input.add("()))");
        expected.add(false);
        input.add("(()()(()");

        for (int i = 0; i < expected.size(); i++) {
            assertEquals(expected.get(i), main.checkParentheses(input.get(i)));
        }
    }

    @Test
    public void testToBinary() {
        assertEquals("11101001", main.toBinary(233));
    }

    @Test
    public void testToBase() {
        assertEquals("11101001", main.toBase(233, 2));
        assertEquals("351", main.toBase(233, 8));
        assertEquals("E9", main.toBase(233, 16));
    }

    @Test
    public void testToPostfix() {
        assertEquals("A B + C D + *", main.toPostfix("( A + B ) * ( C + D )"));
        assertEquals("A B + C *", main.toPostfix("( A + B ) * C"));
        assertEquals("A B C * +", main.toPostfix("A + B * C"));
    }

    @Test
    public void testEvalPostfix() {
        assertEquals(new Integer(3), main.evalPostfix("7 8 + 3 2 + /"));
        assertEquals(new Integer(9), main.evalPostfix("17 10 + 3 * 9 /"));
        assertEquals(new Integer(14), main.evalPostfix("5 1 2 + 4 * + 3 -"));
        assertEquals(new Integer(35), main.evalPostfix("3 4 + 5 *"));
        assertEquals(new Integer(21), main.evalPostfix("1 2 + 3 4 + *"));
    }
}