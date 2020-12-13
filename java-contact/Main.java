//A program that simulates a phone's
//messaging and contact

import java.util.Scanner;

class Main {

    static Scanner scanf = new Scanner(System.in);
    static int selectionMenu = 0;
    static boolean mainMenu = true;
    static boolean quit = false;
    static Contact contacts = new Contact();
    static Messages message = new Messages();

    //List all the main menu functions
    public static void listMenuOptions() {
        System.out.print("Enter a number:\n");
        System.out.print("1) Manage contacts\n");
        System.out.print("2) Messages\n");
        System.out.print("3) Exit\n");
        selectionMenu = scanf.nextInt();
        scanf.nextLine();

        if (selectionMenu != 3) {
            mainMenu = false;
        }
        else if (selectionMenu == 3) {
            quit = true;
        }
        //Selection menu may be wrong
        //Ask the user again
    }

    //List all the contact menu functions
    public static void listContactOptions() {
        System.out.print("1) Show all contacts\n");
        System.out.print("2) Add a new contact\n");
        System.out.print("3) Search for a contact\n");
        System.out.print("4) Delete a contact\n");
        System.out.print("5) Return to main menu\n");
        int contactSelection = scanf.nextInt();
        scanf.nextLine();

        if (contactSelection == 1) {
            contacts.showAllContact();
        }
        else if (contactSelection == 2) {
            contacts.addContact();
        }
        else if (contactSelection == 3) {
            contacts.searchContact();
        }
        else if (contactSelection == 4) {
            contacts.deleteContact();
        }
        else if (contactSelection == 5) {
            selectionMenu = 0;
            mainMenu = true;
        }
        //User may have entered incorrect number

    }
    //List all the message menu functions
    public static void listMessageMenu() {
        System.out.print("1) View all messages\n");
        System.out.print("2) Send a message\n");
        System.out.print("3) Return to main menu\n");
        int messageSelection = scanf.nextInt();
        scanf.nextLine();

        if (messageSelection == 1) {
            message.viewAllMessages();
        }
        else if (messageSelection == 2) {
            message.sendNewMessage(contacts);
        }
        else if (messageSelection == 3) {
            selectionMenu = 0;
            mainMenu = true;
        }

    }

    public static void main(String args[]) {
        System.out.print("Welcome!\n");
        while (!quit) {
            if (selectionMenu == 0 && mainMenu == true) {
                listMenuOptions();
            }
            else if (selectionMenu == 1) {
                listContactOptions();
            }
            else if (selectionMenu == 2) {
                listMessageMenu();
            }
            else if (selectionMenu == 3) {
                quit = true;
            }
        }

        scanf.close();
    }

}