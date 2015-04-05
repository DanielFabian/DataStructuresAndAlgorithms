import java.util.ArrayList;
import java.util.function.BinaryOperator;
import java.util.function.Consumer;

/**
 * Created by Daniel on 05.04.2015.
 */
public class StackAlgorithms {
    public static boolean checkParentheses(String str) {
        Stack<Character> stack = new Stack<>();
        for (Character c : str.toCharArray()) {
            if (c == ')' || c == ']' || c == '}' || c == '>') {
                if (stack.isEmpty() || stack.pop() != c)
                    return false;
            }
            if (c == '(') stack.push(')');
            if (c == '[') stack.push(']');
            if (c == '{') stack.push('}');
            if (c == '<') stack.push('>');
        }
        return stack.isEmpty();
    }

    static String toBinary(int num) {
        return toBase(num, 2);
    }

    static String toBase(int num, int base) {
        char[] digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
        Stack<Character> stack = new Stack<>();
        while (num > 0) {
            stack.push(digits[num % base]);
            num /= base;
        }

        String res = "";
        while (!stack.isEmpty()) {
            res += stack.pop();
        }

        return res;
    }

    public static String toPostfix(String str) {
        String[] tokens = str.split(" ");
        Stack<String> operators = new Stack<>();
        ArrayList<String> res = new ArrayList<>();

        for (String token : tokens) {
            switch (token) {
                case "(":
                    operators.push("(");
                    break;
                case ")":
                    String op = operators.pop();
                    while (!op.equals("(")) {
                        res.add(op);
                        op = operators.pop();
                    }
                    break;
                case "+":
                case "-":
                case "*":
                case "/":
                    while (!operators.isEmpty() && getPrecedence(token) <= getPrecedence(operators.peek()))
                        res.add(operators.pop());
                    operators.push(token);
                    break;
                default:
                    res.add(token);
            }
        }

        while (!operators.isEmpty())
            res.add(operators.pop());

        return String.join(" ", res);
    }

    private static int getPrecedence(String s) {
        switch (s) {
            case "+":
            case "-":
                return 1;
            case "/":
            case "*":
                return 2;
        }
        return 0;
    }

    public static Integer evalPostfix(String s) {
        String[] tokens = s.split(" ");
        Stack<Integer> evalStack = new Stack<>();

        Consumer<BinaryOperator<Integer>> eval = (binOp) -> {
            Integer right = evalStack.pop();
            Integer left = evalStack.pop();
            evalStack.push(binOp.apply(left, right));
        };

        for (String token : tokens) {
            if (token.equals("+")) eval.accept((x, y) -> x + y);
            else if (token.equals("-")) eval.accept((x, y) -> x - y);
            else if (token.equals("*")) eval.accept((x, y) -> x * y);
            else if (token.equals("/")) eval.accept((x, y) -> x / y);
            else evalStack.push(Integer.parseInt(token));
        }

        return evalStack.pop();
    }
}
