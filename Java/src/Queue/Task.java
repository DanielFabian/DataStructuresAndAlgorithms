package Queue;

import java.util.Random;

/**
 * Created by Daniel on 05.04.2015.
 */
public class Task {
    private final int timeStamp;

    private final int pages;

    public Task(int timeStamp, Random rng) {
        this.timeStamp = timeStamp;
        pages = rng.nextInt(20) + 1;
    }

    public int getTimeStamp() {
        return timeStamp;
    }

    public int getPages() {
        return pages;
    }

    public int getWaitTime(int currentTime) {
        return currentTime - timeStamp;
    }
}
