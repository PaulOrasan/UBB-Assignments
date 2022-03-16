package repository.file;

import domain.User;
import domain.validators.Validator;

import java.util.List;

public class UserFileRepository extends AbstractFileRepository<Long, User> {

    public UserFileRepository(String fileName) {
        super(fileName);
    }

    @Override
    public User extractEntity(List<String> attributes) {
        //TODO: implement method
        User user = new User(attributes.get(1),attributes.get(2));
        user.setId(Long.parseLong(attributes.get(0)));
        for (int i = 3; i < attributes.size(); i++){
            user.addFriend(Long.parseLong(attributes.get(i)));
        }
        return user;
    }

    @Override
    protected String createEntityAsString(User entity) {
        String output = entity.getId() + ";" + entity.getFirstName() + ";" + entity.getLastName();
        for (Long ID : entity.getFriends())
            output += ";" + ID;
        return output;
    }
}
