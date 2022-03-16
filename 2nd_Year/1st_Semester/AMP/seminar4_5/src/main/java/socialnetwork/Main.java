package socialnetwork;

import socialnetwork.config.ApplicationContext;
import socialnetwork.domain.Friendship;
import socialnetwork.domain.Tuple;
import socialnetwork.domain.User;
import socialnetwork.domain.validators.FriendshipValidator;
import socialnetwork.domain.validators.UserValidator;
import socialnetwork.repository.Repository;
import socialnetwork.repository.file.FriendshipFileRepository;
import socialnetwork.repository.file.UserFileRepository;
import socialnetwork.repository.memory.InMemoryRepository;
import socialnetwork.service.Service;
import socialnetwork.ui.UI;

public class Main {
    public static void main(String[] args) {
        String userFileName = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.users");
        String friendsFileName = ApplicationContext.getPROPERTIES().getProperty("data.socialnetwork.friendships");
        Repository<Long, User> userRepository = new UserFileRepository(userFileName);
        Repository<Tuple<Long, Long>, Friendship> friendshipRepository = new FriendshipFileRepository(friendsFileName);
        Service service = new Service(userRepository, friendshipRepository);
//
//        Repository<Long,Utilizator> userFileRepository2 = new UtilizatorFile(fileName
//                , new UtilizatorValidator());
//
        UI ui = new UI(service);
        ui.run();
        System.out.println("ok");

    }
}


