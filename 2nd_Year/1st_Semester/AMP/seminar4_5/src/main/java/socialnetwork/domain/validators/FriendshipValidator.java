package socialnetwork.domain.validators;

import socialnetwork.domain.Friendship;

public class FriendshipValidator implements Validator<Friendship> {
    @Override
    public void validate(Friendship entity) throws ValidationException {
        String errors = "";
        if (entity.getId().getLeft() <= 0)
            errors += "Friendship left ID is not valid! Must be a positive integer!\n";
        if (entity.getId().getRight() <= 0)
            errors += "Friendship right ID is not valid! Must be a positive integer!\n";
        if (!errors.equals(""))
            throw new ValidationException(errors);
    }
}
