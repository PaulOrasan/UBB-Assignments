package runner;

import utils.Constants;

import java.time.LocalDateTime;

public class PrinterTaskRunner extends AbstractTaskRunner {

    public PrinterTaskRunner(TaskRunner runner) {
        super(runner);
    }

    private void decorateExecuteOneTask() {
        System.out.println("Am executat taskul la " + LocalDateTime.now().format(Constants.DATE_TIME_FORMATTER));
    }

    @Override
    public void executeOneTask() {
        runner.executeOneTask();
        decorateExecuteOneTask();
    }
}
