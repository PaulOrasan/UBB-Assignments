package repository.database;

import domain.User;
import repository.Repository;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.*;

public class UserDatabaseRepository extends AbstractDatabaseRepository<Long, User> {

    public UserDatabaseRepository(String url, String username, String password) {
        super(url, username, password);
    }

    private List<Long> findFriendsOf(Long id) {
        try {
            connect();
            String sqlQuery = "SELECT * FROM friendships WHERE id1 = ? or id2 = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, id);
            statement.setLong(2, id);
            ResultSet resultSet = statement.executeQuery();
            List<Long> list = new ArrayList<>();
            while (resultSet.next()) {
                if (resultSet.getLong("id1") == id)
                    list.add(resultSet.getLong("id2"));
                else
                    list.add(resultSet.getLong("id1"));
            }
            return list;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public User findOne(Long id) {
        try {
            connect();
            String sqlQuery = "SELECT * FROM users WHERE id = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next() == false)
                return null;
            User user = new User(resultSet.getString("first_name"), resultSet.getString("last_name"));
            user.setId(resultSet.getLong("id"));
            user.setFriends(findFriendsOf(id));
            return user;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Iterable<User> findAll() {
        try {
            connect();
            String sqlQuery = "SELECT * FROM users";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            ResultSet resultSet = statement.executeQuery();
            Set<User> users = new HashSet<>();
            while (resultSet.next()) {
                User user = new User(resultSet.getString("first_name"), resultSet.getString("last_name"));
                user.setId(resultSet.getLong("id"));
                user.setFriends(findFriendsOf(user.getId()));
                users.add(user);
            }
            return users;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public User save(User entity) {
        try {
            connect();
            String sqlQuery = "INSERT INTO users (first_name, last_name) VALUES (?, ?)";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setString(1, entity.getFirstName());
            statement.setString(2, entity.getLastName());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public User delete(Long id) {
        try {
            connect();
            User user = findOne(id);
            if (user == null)
                return null;

            String sqlQueryX = "DELETE FROM friendships WHERE id1 = ? OR id2 = ?";
            PreparedStatement statementX = connection.prepareStatement(sqlQueryX);
            statementX.setLong(1, id);
            statementX.setLong(2, id);
            statementX.executeUpdate();

            String sqlQuery = "DELETE FROM users WHERE id = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, id);
            statement.executeUpdate();
            return user;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public User update(User entity) {
        try {
            connect();
            User user = findOne(entity.getId());
            if (user == null)
                return entity;
            String sqlQuery = "UPDATE users  SET first_name = ?, last_name = ? WHERE id = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setString(1, entity.getFirstName());
            statement.setString(2, entity.getLastName());
            statement.setLong(3, entity.getId());
            statement.executeUpdate();
            return null;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public void syncContent() {

    }
}
