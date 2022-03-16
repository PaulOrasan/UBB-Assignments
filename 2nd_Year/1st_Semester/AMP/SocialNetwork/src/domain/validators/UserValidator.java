package domain.validators;

import domain.User;

public class UserValidator implements Validator<User> {

    /**
     * Validates a User if the ID is a positive integer and the names contain only alphabet characters and spaces
     * @param entity - object of type User to be validated
     * @throws ValidationException - if the User is not valid
     */
    @Override
    public void validate(User entity) throws ValidationException {
        //TODO: implement method validate
        String errors = "";
        if (entity.getId() <= 0)
            errors += "ID is not valid! Must be a positive integer!\n";
        if (!entity.getFirstName().matches("[a-zA-Z ]+"))
            errors += "First name is not valid! Must contain only alphabet characters and spaces!";
        if (!entity.getLastName().matches("[a-zA-Z ]+"))
            errors += "Last name is not valid! Must contain only alphabet characters and spaces!";
        if (!errors.equals(""))
            throw new ValidationException(errors);
    }
}
