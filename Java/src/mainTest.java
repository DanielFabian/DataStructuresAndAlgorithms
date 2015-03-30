import com.google.common.base.Stopwatch;
import org.junit.Assert;
import org.junit.Test;

import java.util.concurrent.TimeUnit;

import static org.junit.Assert.*;

/**
 * Created by Daniel on 30.03.2015.
 */
public class mainTest {

    @Test
    public void test_sum_of_n() throws Exception {
        Assert.assertEquals(main.sum_of_n(10), 55);
    }

    @Test
    public void benchmark_sum_of_n()
    {
        int n = 100;
        Stopwatch sw = Stopwatch.createStarted();
        for (int i = 0; i < n; i++) {
            main.sum_of_n(10000);
        }
        sw.stop();

        printBenchmark("sum_of_n", sw.elapsed(TimeUnit.NANOSECONDS), n);
    }

    private static void printBenchmark(String name, long nanoseconds, int n)
    {
        double averageTime = nanoseconds / (double) n;
        if (averageTime < 1000){
            System.out.printf("%s, iterations %d, %0.3f ns/op", name, n, averageTime);
        }
        else {
            System.out.printf("%s, iterations %d, %d ns/op", name, n, (int) averageTime);
        }
    }
}