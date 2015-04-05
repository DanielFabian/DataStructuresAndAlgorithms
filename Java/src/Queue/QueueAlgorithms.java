package Queue;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Daniel on 05.04.2015.
 */
public class QueueAlgorithms {
    public static String hotPotato(String[] names, int num) {
        Queue<String> queue = new Queue<String>();
        for (String name : names) {
            queue.enqueue(name);
        }

        while (queue.size() > 1) {
            for (int i = 0; i < num; i++) {
                queue.enqueue(queue.dequeue());
            }

            queue.dequeue();
        }

        return queue.dequeue();
    }

    public static void PrinterQueue(Random rng, int numSeconds, int pagesPerMinute) {
        Printer labprinter = new Printer(pagesPerMinute);
        Queue<Task> printQueue = new Queue<Task>();
        ArrayList<Integer> waitingtimes = new ArrayList<>();

        for (int currentSecond = 0; currentSecond < numSeconds; currentSecond++) {
            if (newPrintTask(rng)) {
                printQueue.enqueue(new Task(currentSecond, rng));
            }

            if (!labprinter.isBusy() && !printQueue.isEmpty()) {
                Task nexttask = printQueue.dequeue();
                waitingtimes.add(nexttask.getWaitTime(currentSecond));
                labprinter.startNext(nexttask);
            }

            labprinter.tick();
        }

        double avg = 0;
        for (Integer i : waitingtimes) {
            avg += i.doubleValue();
        }
        avg /= waitingtimes.size();

        System.out.printf("average wait: %6.2f seconds %3d tasks remaining.\n", avg, printQueue.size());
    }

    private static boolean newPrintTask(Random rng) {
        return rng.nextInt(180) + 1 == 180;
    }
}
