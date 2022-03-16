package main;

import container.Strategy;
import model.MessageTask;
import runner.DelayTaskRunner;
import runner.PrinterTaskRunner;
import runner.StrategyTaskRunner;

import java.time.LocalDateTime;

public class Main {

    public static void main(String[] args) {
        // write your code here
        MessageTask[] messageTasks = createMessageTaskArray();
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        for (var task : messageTasks)
            strategyTaskRunner.addTask(task);
        strategyTaskRunner.executeAll();

        System.out.println();
        for (var task : messageTasks)
            strategyTaskRunner.addTask(task);
        DelayTaskRunner delayTaskRunner = new DelayTaskRunner(strategyTaskRunner);
        delayTaskRunner.executeAll();

        System.out.println();
        for (var task : messageTasks)
            strategyTaskRunner.addTask(task);
        PrinterTaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.executeAll();

    }

    public static MessageTask[] createMessageTaskArray() {

        MessageTask m1 = new MessageTask("ID1", "Descr1", "Mes1", "to1", "from1",
                LocalDateTime.now());
        MessageTask m2 = new MessageTask("ID2", "Descr2", "Mes2", "to2", "from2",
                LocalDateTime.now());
        MessageTask m3 = new MessageTask("ID3", "Descr3", "Mes3", "to3", "from3",
                LocalDateTime.now());
        MessageTask m4 = new MessageTask("ID4", "Descr4", "Mes4", "to4", "from4",
                LocalDateTime.now());
        MessageTask m5 = new MessageTask("ID5", "Descr5", "Mes5", "to5", "from5",
                LocalDateTime.now());
        return new MessageTask[]{m1, m2, m3, m4, m5};
    }
}
