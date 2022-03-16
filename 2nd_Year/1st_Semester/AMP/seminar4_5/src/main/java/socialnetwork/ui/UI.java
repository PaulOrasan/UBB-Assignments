package socialnetwork.ui;

import socialnetwork.domain.User;
import socialnetwork.service.Service;
import socialnetwork.service.ServiceException;

import java.util.List;
import java.util.Scanner;

public class UI {

    private Service service;
    private  Scanner scanner;

    public UI(Service service) {
        this.service = service;
        scanner = new Scanner(System.in);
    }

    public void run() {
        String command = "";
        help();
        while (!command.equals("exit")) {
            System.out.print(">>> ");
            command = scanner.nextLine().strip();
            try {
                switch (command) {
                    case "add user":
                        addUser();
                        break;
                    case "add friends":
                        addFriendship();
                        break;
                    case "del user":
                        deleteUser();
                        break;
                    case "del friends":
                        deleteFriendship();
                        break;
                    case "group number":
                        numberOfGroups();
                        break;
                    case "top group":
                        topGroup();
                        break;
                    case "help":
                        help();
                        break;
                    default:
                        System.out.println("Unrecognized command!");
                }
            } catch (ServiceException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    private void addUser() {
        System.out.print("User ID: ");
        String id = scanner.nextLine();
        System.out.print("User first name: ");
        String firstName = scanner.nextLine();
        System.out.print("User second name: ");
        String lastName = scanner.nextLine();
        service.addUser(id, firstName, lastName);
        System.out.println("User added successfully!");
    }

    private void addFriendship() {
        System.out.print("First user ID: ");
        String id1 = scanner.nextLine();
        System.out.print("Second user ID: ");
        String id2 = scanner.nextLine();
        service.addFriendship(id1, id2);
        System.out.println("Friendship registered successfully!");
    }

    private void deleteUser() {
        System.out.print("User ID: ");
        String id = scanner.nextLine();
        service.deleteUser(id);
        System.out.println("User deleted successfully!");
    }

    private void deleteFriendship() {
        System.out.print("First user ID: ");
        String id1 = scanner.nextLine();
        System.out.print("Second user ID: ");
        String id2 = scanner.nextLine();
        service.deleteFriendship(id1, id2);
        System.out.println("Friendship removed successfully!");
    }

    private void numberOfGroups() {
        System.out.println("The total number of groups is " + service.getNumberOfGroups());
    }

    private void showUsers(List<User> list) {
        for (User user : list) {
            System.out.print(user.toString());
            System.out.println("Friends:\n ");
            for (Long friendID: user.getFriends())
                System.out.print(service.findUser(friendID).toString());
            System.out.println();
        }
    }
    private void topGroup() {
        List<User> group = service.getMostSociableCommunity();
        showUsers(group);
    }

    private void help() {
        System.out.println("Type the commands inside < > without < >: ");
        System.out.println("<add user> to add a new user");
        System.out.println("<add friends> to register a new friendship");
        System.out.println("<del user> to delete an existing user");
        System.out.println("<del friends> to remove an existing friendship");
        System.out.println("<group number> to see the number of existing groups");
        System.out.println("<top group> to see the members of the most sociable group");
        System.out.println("<help> to see this menu again");
        System.out.println("<exit> to close the application");
    }
}
