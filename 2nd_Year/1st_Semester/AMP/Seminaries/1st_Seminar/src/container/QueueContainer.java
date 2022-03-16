package container;

import model.Task;

public class QueueContainer extends OrderedContainer {

    @Override
    public Task remove() {
        if (!isEmpty()) {
            Task t = tasks[0];
            for (int i = 1; i < size; i++)
                tasks[i - 1] = tasks[i];
            size--;
            return t;
        }
        return null;
    }

}
