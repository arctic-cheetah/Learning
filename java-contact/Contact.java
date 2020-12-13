import java.util.ArrayList;
import java.util.Scanner;

class Contact {
    
    private ArrayList<Person> contacts = new ArrayList<Person>();
    private Scanner scanf = new Scanner(System.in);

    public void addContact() {
        System.out.print("Enter a name: ");
        String name = scanf.nextLine();

        System.out.print("Enter a phone number: ");
        String phoneNumber = scanf.nextLine();

        System.out.print("Enter an email: ");
        String email = scanf.nextLine();

        Person person = new Person(name, phoneNumber, email);
        //Input checking
        if (name.equals("") || phoneNumber.equals("") || email.equals("")) {
            System.out.print("Please enter all the details\n");
            addContact();
        }
        else {
            //Check for duplicate input
            boolean hasDup = false;
            for (int i = 0; i < contacts.size(); i +=1) {
                if (name.equals(contacts.get(i).getName())) {
                    hasDup = true;
                }
            }
            //Duplicate contact present
            if (hasDup) {
                System.out.println("Duplicate contact, please re-enter unique details");
                addContact();
            }
            else {
                contacts.add(person);
                System.out.print("Contact added!\n");
            }
        }
    }

    public void showAllContact() {
        System.out.print("------------------------------\n");
        for (int i = 0; i < contacts.size(); i +=1) {
            contacts.get(i).printContact();
        }
        System.out.print("------------------------------\n");
    }

    public void searchContact() {
        System.out.println("Enter a name to search a contact");
        String name = scanf.nextLine();
        //Check for valid input
        if (name.equals("")) {
            searchContact();
        }
        else {
            boolean found = false;
            System.out.print("------------------------------\n");
            for (int i = 0; i < contacts.size(); i +=1) {
                Person temp = contacts.get(i);
                found = name.equals(temp.getName());
                if (found) {
                    temp.printContact();
                    break;
                }
            }
            System.out.print("------------------------------\n");
            if (!found) {
                System.out.print("Contact not found\n\n");
            }
        }
    }

    public void deleteContact() {
        System.out.println("Enter a name to delete a contact");
        String name = scanf.nextLine();
        //Check for valid input
        if (name.equals("")) {
            deleteContact();
        }
        else {
            boolean found = false;
            System.out.print("------------------------------\n");
            for (int i = 0; i < contacts.size(); i +=1) {
                Person temp = contacts.get(i);
                found = name.equals(temp.getName());
                if (found) {
                    contacts.remove(i);
                    System.out.print("Contact " + name + " removed\n");
                    break;
                }
            }
            System.out.print("------------------------------\n");
            if (!found) {
                System.out.print("Contact not found\n\n");
            } 
        } 
    }
    public boolean doesContactExist(String name) {
        for (Person c : contacts) {
            if (name.equals(c.getName())) {
                return true;
            }
        }
        //Contact not found
        return false;
    }
}