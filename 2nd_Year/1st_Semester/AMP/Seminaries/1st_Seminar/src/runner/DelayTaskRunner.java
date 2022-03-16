package runner;

import utils.Constants;

import java.time.LocalDateTime;

public class DelayTaskRunner extends AbstractTaskRunner {

    public DelayTaskRunner(TaskRunner runner) {
        super(runner);
    }

    private void decorateExecuteOneTask() {
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void executeOneTask() {
        decorateExecuteOneTask();
        runner.executeOneTask();
    }
}
