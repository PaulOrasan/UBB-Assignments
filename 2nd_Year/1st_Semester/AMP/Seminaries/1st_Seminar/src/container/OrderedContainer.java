package container;

import model.Task;

public abstract class OrderedContainer implements Container{

    protected Task[] tasks;
    protected int size;

    public OrderedContainer() {
        tasks = new Task[10];
        size = 0;
    }

    @Override
    public abstract Task remove();

    @Override
    public void add(Task task) {
        if (size == tasks.length) {
            Task[] t = new Task[2 * tasks.length];
            System.arraycopy( tasks, 0, t, 0, tasks.length );
            tasks = t;
        }
        tasks[size] = task;
        size++;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }
}
