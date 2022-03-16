package domain.validators;

import domain.Friendship;

public class FriendshipValidator implements Validator<Friendship> {

    /**
     * Validates a Friendship if the IDs are positive integers
     * @param entity - object of type Friendship to be validated
     * @throws ValidationException - if the User is not valid
     */
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
