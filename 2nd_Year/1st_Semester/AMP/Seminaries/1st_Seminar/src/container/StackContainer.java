package container;

import model.Task;

public class StackContainer extends OrderedContainer {

    @Override
    public Task remove() {
        if (!isEmpty()) {
            size--;
            return tasks[size];
        }
        return null;
    }

}
