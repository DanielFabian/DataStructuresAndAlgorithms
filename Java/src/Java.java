/**
 * Created by Daniel on 28.03.2015.
 */
public class Java {
    public static void main(String[] args)
    {
        System.out.println("Hello World");

        System.out.println(sum_of_n(10));
    }

    private static int sum_of_n(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += i;
        }

        return res;
    }
}
