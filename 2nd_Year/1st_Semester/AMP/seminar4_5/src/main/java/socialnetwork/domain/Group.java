package socialnetwork.domain;

import java.util.ArrayList;
import java.util.List;

public class Group {

    private List<Long> usersID;

    public Group() {
        usersID = new ArrayList<>();
    }

    /**
     * Adds a new user to the group of users
     * @param ID - the ID of the user
     */
    public void addUser(Long ID) {
        usersID.add(ID);
    }

    /**
     * Finds the size of the group of ysers
     * @return integer which describes the size
     */
    public int getSize() {
        return usersID.size();
    }

    /**
     * Finds all IDs of the users from this group
     * @return a list of all IDs
     */
    public List<Long> getUsers() {
        return usersID;
    }
}
