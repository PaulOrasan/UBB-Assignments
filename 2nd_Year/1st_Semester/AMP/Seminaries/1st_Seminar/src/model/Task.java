package model;

import java.util.Objects;

public abstract class Task {
    private String taskID;
    private String descriere;

    public Task(String taskID, String descriere) {
        this.taskID = taskID;
        this.descriere = descriere;
    }

    public String getTaskID() {
        return taskID;
    }

    public void setTaskID(String taskID) {
        this.taskID = taskID;
    }

    public String getDescriere() {
        return descriere;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Task task = (Task) o;
        return taskID.equals(task.taskID) && descriere.equals(task.descriere);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskID, descriere);
    }

    @Override
    public String toString() {
        return "Task{" +
                "taskID='" + taskID + '\'' +
                ", descriere='" + descriere + '\'' +
                '}';
    }

    public abstract void execute();
}
