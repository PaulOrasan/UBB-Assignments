package socialnetwork.domain;

import java.time.LocalDateTime;


public class Friendship extends Entity<Tuple<Long,Long>> {

    LocalDateTime date;

    public Friendship() {
        date = LocalDateTime.now();
    }

    /**
     *  finds the date when the friendship was created
     * @return LocalDateTime value which describes the date
     */
    public LocalDateTime getDate() {
        return date;
    }

    /**
     * sets the date of when the friendship was created
     * @param date - LocalDateTime which describes the new date
     */
    public void setDate(LocalDateTime date) {
        this.date = date;
    }
}
