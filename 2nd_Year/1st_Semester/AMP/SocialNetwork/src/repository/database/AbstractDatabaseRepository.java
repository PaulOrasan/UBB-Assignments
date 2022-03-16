package repository.database;

import domain.Entity;
import repository.Repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public abstract class AbstractDatabaseRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {

    private String url;
    private String username;
    private String password;

    protected Connection connection;

    public AbstractDatabaseRepository(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
        connection = null;
    }

    protected void connect() throws SQLException {
        if (connection == null || connection.isClosed())
            connection = DriverManager.getConnection(url, username, password);
    }

}
