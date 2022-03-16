package socialnetwork.domain;

import java.io.Serializable;

public class Entity<ID> implements Serializable {

    private static final long serialVersionUID = 7331115341259248461L;
    private ID id;

    /**
     * finds the id of the entity
     * @return the id of the entity of type ID
     */
    public ID getId() {
        return id;
    }

    /**
     * sets the id of the entity
     * @param id - the new id of the entity of type ID
     */
    public void setId(ID id) {
        this.id = id;
    }
}