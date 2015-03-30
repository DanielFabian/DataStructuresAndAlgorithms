import com.google.common.base.Stopwatch;

import java.util.concurrent.TimeUnit;

/**
 * Created by Daniel on 28.03.2015.
 */
public class main {
    public static void main(String[] args)
    {
        System.out.println("Hello World");

        System.out.println(sum_of_n(10));

        for (int i = 0; i < 5; i++) {
            Stopwatch sw = Stopwatch.createStarted();
            long res = sum_of_n(1000000);
            sw.stop();
            System.out.printf("sum_of_n 10^6 = %d, took %9.7f seconds\n", res, sw.elapsed(TimeUnit.MICROSECONDS) / 1000000.0);
        }
    }

    public static long sum_of_n(int n)
    {
        long res = 0;
        for (int i = 1; i <= n; i++) {
            res += i;
        }

        return res;
    }
}
