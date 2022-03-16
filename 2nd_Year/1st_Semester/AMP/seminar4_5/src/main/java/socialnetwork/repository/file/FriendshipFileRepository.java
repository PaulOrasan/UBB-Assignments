package socialnetwork.repository.file;

import socialnetwork.domain.Friendship;
import socialnetwork.domain.Tuple;
import socialnetwork.domain.User;
import socialnetwork.domain.validators.Validator;

import java.time.LocalDateTime;
import java.util.List;

public class FriendshipFileRepository extends AbstractFileRepository<Tuple<Long, Long>, Friendship>{


    public FriendshipFileRepository(String fileName) {
        super(fileName);
    }

    @Override
    public Friendship extractEntity(List<String> attributes) {
        Friendship friendship = new Friendship();
        friendship.setId(new Tuple<>(Long.parseLong(attributes.get(0)), Long.parseLong(attributes.get(1))));
        friendship.setDate(LocalDateTime.parse(attributes.get(2)));
        return friendship;
    }

    @Override
    protected String createEntityAsString(Friendship entity) {
        return entity.getId().getLeft() + ";" + entity.getId().getRight() + ";" + entity.getDate();
    }
}
