package repository.database;

import domain.Friendship;
import domain.Tuple;
import domain.User;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashSet;
import java.util.Set;

public class FriendshipDatabaseRepository extends AbstractDatabaseRepository<Tuple<Long, Long>, Friendship> {

    public FriendshipDatabaseRepository(String url, String username, String password) {
        super(url, username, password);
    }

    @Override
    public Friendship findOne(Tuple<Long, Long> id) {
        try {
            connect();
            String sqlQuery = "SELECT * FROM friendships WHERE id1 = ? and id2 = ? or id1 = ? and id2 = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, id.getLeft());
            statement.setLong(2, id.getRight());
            statement.setLong(3, id.getRight());
            statement.setLong(4, id.getLeft());
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next() == false)
                return null;
            Friendship friendship = new Friendship();
            friendship.setId(id);
            friendship.setDate(resultSet.getDate("date").toLocalDate());
            return friendship;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Iterable<Friendship> findAll() {
        try {
            connect();
            String sqlQuery = "SELECT * FROM friendships";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            ResultSet resultSet = statement.executeQuery();
            Set<Friendship> friendships = new HashSet<>();
            while (resultSet.next()) {
                Friendship friendship = new Friendship();
                friendship.setId(new Tuple<>(resultSet.getLong("id1"), resultSet.getLong("id2")));
                friendship.setDate(resultSet.getDate("date").toLocalDate());
                friendships.add(friendship);
            }
            return friendships;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Friendship save(Friendship entity) {
        try {
            connect();
            Friendship friendship = findOne(entity.getId());
            if (friendship != null)
                return friendship;
            String sqlQuery = "INSERT INTO friendships (id1, id2, date) VALUES (?, ?, ?)";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, entity.getId().getLeft());
            statement.setLong(2, entity.getId().getRight());
            statement.setDate(3, Date.valueOf(entity.getDate()));
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Friendship delete(Tuple<Long, Long> id) {
        try {
            connect();
            Friendship friendship = findOne(id);
            if (friendship == null)
                return null;
            String sqlQuery = "DELETE FROM friendships WHERE id1 = ? and id2 = ? or id1 = ? and id2 = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setLong(1, id.getLeft());
            statement.setLong(2, id.getRight());
            statement.setLong(3, id.getRight());
            statement.setLong(4, id.getLeft());
            statement.executeUpdate();
            return friendship;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Friendship update(Friendship entity) {
        try {
            connect();
            Friendship friendship = findOne(entity.getId());
            if (friendship == null)
                return entity;
            String sqlQuery = "UPDATE friendships  SET date = ? WHERE id1 = ? and id2 = ? or id1 = ? and id2 = ?";
            PreparedStatement statement = connection.prepareStatement(sqlQuery);
            statement.setDate(1, Date.valueOf(entity.getDate()));
            statement.setLong(2, entity.getId().getLeft());
            statement.setLong(3, entity.getId().getRight());
            statement.setLong(4, entity.getId().getRight());
            statement.setLong(5, entity.getId().getLeft());
            ResultSet resultSet = statement.executeQuery();
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
