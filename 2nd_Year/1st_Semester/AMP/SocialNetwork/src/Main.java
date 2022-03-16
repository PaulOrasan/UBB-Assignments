import config.ApplicationContext;
import domain.Friendship;
import domain.Tuple;
import domain.User;
import repository.Repository;
import repository.database.FriendshipDatabaseRepository;
import repository.database.UserDatabaseRepository;
import repository.file.FriendshipFileRepository;
import repository.file.UserFileRepository;
import service.Service;
import ui.UI;

public class Main {
    public static void main(String[] args) {
        String userFileName = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.users");
        String friendsFileName = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.friendships");

        String url = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.database");
        String username = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.username");
        String password = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.password");

        Repository<Long, User> userRepository = new UserDatabaseRepository(url, username, password);
        Repository<Tuple<Long, Long>, Friendship> friendshipRepository = new FriendshipDatabaseRepository(url, username, password);

        Service service = new Service(userRepository, friendshipRepository);

        UI ui = new UI(service);
        ui.run();
    }
}


