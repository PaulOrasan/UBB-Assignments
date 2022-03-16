package socialnetwork.service;

import socialnetwork.domain.Friendship;
import socialnetwork.domain.Group;
import socialnetwork.domain.Tuple;
import socialnetwork.domain.User;
import socialnetwork.domain.validators.FriendshipValidator;
import socialnetwork.domain.validators.UserValidator;
import socialnetwork.domain.validators.ValidationException;
import socialnetwork.repository.Repository;

import java.util.*;

public class Service {
    private Repository<Long, User> repoUser;
    private Repository<Tuple<Long, Long>, Friendship> repoFriendship;
    private UserValidator userValidator;
    private FriendshipValidator friendshipValidator;

    public Service(Repository<Long, User> repoUser, Repository<Tuple<Long, Long>, Friendship> repoFriendship) {
        this.repoUser = repoUser;
        this.repoFriendship = repoFriendship;
        userValidator = new UserValidator();
        friendshipValidator = new FriendshipValidator();
    }

    public void addUser(String ID, String firstName, String lastName) throws ServiceException {
        try {
            User user = new User(firstName, lastName);
            user.setId(Long.parseLong(ID));
            userValidator.validate(user);
            if (repoUser.save(user) != null) {
                throw new ServiceException("A user with the same ID already exists!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        } catch (ValidationException e) {
            throw new ServiceException(e.getMessage());
        }
    }

    public void deleteUser(String strID) throws ServiceException {
        try {
            Long ID = Long.parseLong(strID);
            User result = repoUser.delete(ID);
            if (result != null) {
                for (Long id : result.getFriends()) {
                    repoFriendship.delete(new Tuple<>(ID, id));
                    repoUser.findOne(id).removeFriend(ID);
                }
                repoFriendship.syncContent();
                repoUser.syncContent();
            } else {
                throw new ServiceException("No user with the same ID exists!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        }
    }

    public void addFriendship(String strID1, String strID2) {
        try {
            Long ID1 = Long.parseLong(strID1);
            Long ID2 = Long.parseLong(strID2);
            Friendship friendship = new Friendship();
            friendship.setId(new Tuple<>(ID1, ID2));
            friendshipValidator.validate(friendship);
            Friendship result = repoFriendship.save(friendship);
            if (result == null) {
                repoUser.findOne(ID1).addFriend(ID2);
                repoUser.findOne(ID2).addFriend(ID1);
                repoUser.syncContent();
            } else {
                throw new ServiceException("Friendship already registered!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        }
    }

    public void deleteFriendship(String strID1, String strID2) {
        try {
            Long ID1 = Long.parseLong(strID1);
            Long ID2 = Long.parseLong(strID2);
            Friendship result = repoFriendship.delete(new Tuple<>(ID1, ID2));
            if (result != null) {
                repoUser.findOne(ID1).removeFriend(ID2);
                repoUser.findOne(ID2).removeFriend(ID1);
                repoUser.syncContent();
            } else {
                throw new ServiceException("Friendship already registered!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        }
    }

    public Iterable<User> getAll(){
        return repoUser.findAll();
    }

    private List<Group> getGroups() {
        List<Group> groupList = new ArrayList<>();

        Set<Long> visited = new HashSet<>();
        Iterable<User> users = getAll();
        for (User user : users){
            if (!visited.contains(user.getId())) {
                Group group = new Group();
                Queue<Long> q = new LinkedList<>();
                q.add(user.getId());
                while (!q.isEmpty()) {
                    Long container = q.remove();
                    visited.add(container);
                    group.addUser(container);
                    for (Long userID : repoUser.findOne(container).getFriends()) {
                        if (!visited.contains(userID))
                            q.add(userID);
                    }
                }
                groupList.add(group);
            }
        }
        return groupList;
    }

    public int getNumberOfGroups() {
        return getGroups().size();
    }

    public List<User> getMostSociableCommunity() {
        List<Group> list = getGroups();
        int maximum = 0;
        Group maximumGroup = list.get(0);
        for (Group group : list) {
            if (group.getSize() > maximum) {
                maximum = group.getSize();
                maximumGroup = group;
            }
        }
        List<User> users = new ArrayList<>();
        for (Long id : maximumGroup.getUsers())
            users.add(repoUser.findOne(id));
        return users;
    }

    public User findUser(Long ID) {
        return repoUser.findOne(ID);
    }
}