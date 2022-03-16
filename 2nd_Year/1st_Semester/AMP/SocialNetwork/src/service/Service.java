package service;

import domain.*;
import domain.validators.FriendshipValidator;
import domain.validators.UserValidator;
import domain.validators.ValidationException;
import repository.Repository;

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

    /**
     * Adds a new user
     * @param firstName - String which describes the first name
     * @param lastName - String which describes the second name
     * @throws ServiceException if a user with the same ID already exists or
     *                          if the ID is invalid or
     *                          if the User is invalid
     */
    public void addUser(String firstName, String lastName) throws ServiceException {
        try {
            User user = new User(firstName, lastName);
            user.setId(1L);
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

    /**
     * Deletes a user
     * @param strID - String which describes the ID
     *              must be convertable to Long
     * @throws ServiceException if the ID cannot be converted to Long or
     *                          if the ID is invalid or
     *                          if no user with that ID exists
     */
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

    /**
     *
     * @param strID1 - String which describes the ID of the first user
     * @param strID2 - String which describes the ID of the second user
     * @throws ServiceException if the friendship already exists
     *                          if the IDs are not valid
     */
    public void addFriendship(String strID1, String strID2) throws ServiceException {
        try {
            Long ID1 = Long.parseLong(strID1);
            Long ID2 = Long.parseLong(strID2);
            Friendship friendship = new Friendship();
            friendship.setId(new Tuple<>(ID1, ID2));
            friendshipValidator.validate(friendship);
            Friendship result = repoFriendship.save(friendship);
            if (result == null) {
                User user1 = repoUser.findOne(ID1);
                if (user1 != null)
                    user1.addFriend(ID2);
                else
                    throw new ServiceException("The user with ID " + ID1 + " doesn't exist!");
                User user2 = repoUser.findOne(ID2);
                if (user2 != null)
                    user2.addFriend(ID1);
                else
                    throw new ServiceException("The user with ID " + ID2 + " doesn't exist!");
                repoUser.syncContent();
            } else {
                throw new ServiceException("Friendship already registered!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        }
    }

    /**
     * Removes a friendship
     * @param strID1 - String which describes the ID of the first user
     * @param strID2 - String which describes the ID of the second user
     * @throws ServiceException if the IDs are not valid
     *                          if the friendship does not exist
     */
    public void deleteFriendship(String strID1, String strID2) throws ServiceException {
        try {
            Long ID1 = Long.parseLong(strID1);
            Long ID2 = Long.parseLong(strID2);
            Friendship result = repoFriendship.delete(new Tuple<>(ID1, ID2));
            if (result != null) {
                repoUser.findOne(ID1).removeFriend(ID2);
                repoUser.findOne(ID2).removeFriend(ID1);
                repoUser.syncContent();
            } else {
                throw new ServiceException("Friendship doesn't exist!");
            }
        } catch (NumberFormatException e) {
            throw new ServiceException("ID is not valid! Must be a positive integer!");
        }
    }

    /**
     * Finds the list of users
     * @return Iterable of Users
     */
    public Iterable<User> getAll(){
        return repoUser.findAll();
    }

    /**
     * Finds the network of users and friendships
     * @return Network object of IDs
     */
    private Network getNetwork() {
        Network network = new Network();
        for (User user : repoUser.findAll()){
            network.addNode(user.getId(), user.getFriends());
        }
        return network;
    }

    /**
     * Finds the most sociable community
     * @return List of Users that belong to the most sociable community
     */
    public List<User> getMostSociableCommunity() {
        Group bestGroup = getNetwork().getBestGroup();
        if (bestGroup == null)
            throw new ServiceException("There are no users registered!");
        List<User> result = new ArrayList<>();
        for (Long ID : bestGroup.getUsers())
            result.add(repoUser.findOne(ID));
        return result;
    }

    /**
     * Finds the number of groups inside the community
     * @return int which describes the number of groups
     */
    public int getNumberOfGroups() {
        return getNetwork().getNumberGroups();
    }


    /**
     * Finds a User based on its ID
     * @param ID - Long which describes the ID
     * @return - User object which coresponds to the ID
     *           null if no User with that ID was found
     */
    public User findUser(Long ID) {
        return repoUser.findOne(ID);
    }

}