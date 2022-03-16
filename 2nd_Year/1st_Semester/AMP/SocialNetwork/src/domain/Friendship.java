package domain;

import java.time.LocalDate;


public class Friendship extends Entity<Tuple<Long,Long>> {

    private LocalDate date;

    public Friendship() {
        date = LocalDate.now();
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }
}
