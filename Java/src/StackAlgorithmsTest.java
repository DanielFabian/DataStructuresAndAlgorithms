import org.junit.Test;

import java.util.ArrayList;

import static org.junit.Assert.*;

/**
 * Created by Daniel on 05.04.2015.
 */
public class StackAlgorithmsTest {
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
            assertEquals(expected.get(i), StackAlgorithms.checkParentheses(input.get(i)));
        }
    }

    @Test
    public void testToBinary() {
        assertEquals("11101001", StackAlgorithms.toBinary(233));
    }

    @Test
    public void testToBase() {
        assertEquals("11101001", StackAlgorithms.toBase(233, 2));
        assertEquals("351", StackAlgorithms.toBase(233, 8));
        assertEquals("E9", StackAlgorithms.toBase(233, 16));
    }

    @Test
    public void testToPostfix() {
        assertEquals("A B + C D + *", StackAlgorithms.toPostfix("( A + B ) * ( C + D )"));
        assertEquals("A B + C *", StackAlgorithms.toPostfix("( A + B ) * C"));
        assertEquals("A B C * +", StackAlgorithms.toPostfix("A + B * C"));
    }

    @Test
    public void testEvalPostfix() {
        assertEquals(new Integer(3), StackAlgorithms.evalPostfix("7 8 + 3 2 + /"));
        assertEquals(new Integer(9), StackAlgorithms.evalPostfix("17 10 + 3 * 9 /"));
        assertEquals(new Integer(14), StackAlgorithms.evalPostfix("5 1 2 + 4 * + 3 -"));
        assertEquals(new Integer(35), StackAlgorithms.evalPostfix("3 4 + 5 *"));
        assertEquals(new Integer(21), StackAlgorithms.evalPostfix("1 2 + 3 4 + *"));
    }
}
