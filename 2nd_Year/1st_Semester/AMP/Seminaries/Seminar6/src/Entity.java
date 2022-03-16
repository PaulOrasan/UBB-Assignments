import java.io.Serializable;

public abstract class Entity<ID> implements Serializable {
    private ID id;
    private static final long serialVersionUID = 4500794925126064682L;

    public ID getId() {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }
}
