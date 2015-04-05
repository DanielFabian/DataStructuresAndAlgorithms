package Queue;

/**
 * Created by Daniel on 05.04.2015.
 */
public class Printer {
    private final int ppm;
    private Task currentTask;
    private int timeRemaining;

    public Printer(int ppm) {
        this.ppm = ppm;
    }

    public void tick() {
        if (currentTask != null) {
            timeRemaining--;
            if (timeRemaining <= 0) {
                currentTask = null;
            }
        }
    }

    public boolean isBusy() {
        return currentTask != null;
    }

    public void startNext(Task task) {
        currentTask = task;
        timeRemaining = task.getPages() * 60 / ppm;
    }
}
