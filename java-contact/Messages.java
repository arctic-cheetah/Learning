import java.util.ArrayList;
import java.util.Scanner;

class Messages {
    private ArrayList<Txt> message = new ArrayList<Txt>();
    private Scanner scanf = new Scanner(System.in);
    class Txt {
        private String recipient;
        private String txt;

        public Txt (String recipient, String txt) {
            this.recipient = recipient;
            this.txt = txt;
        }
        public void printMessage() {
            System.out.println("Recipient: " + recipient);
            System.out.println("Message: " + txt);
        }
    }

    public void viewAllMessages () {
        System.out.print("-----------------------------\n");
        for (int i = 0; i < message.size(); i +=1) {
            message.get(i).printMessage();
        }
        System.out.print("------------------------------\n");
    }

    public void sendNewMessage(Contact contacts) {
        System.out.print("Enter a recipient: ");
        String recipient = scanf.nextLine();

        //Check that the contact exists
        if (contacts.doesContactExist(recipient)) {
            System.out.print("Enter a message: ");
            //Check for empty details
            String txt = scanf.nextLine();
            if (recipient.equals("") || txt.equals("")) {
                sendNewMessage(contacts);
            }
            else {
                Txt newMessage = new Txt(recipient, txt);
                message.add(newMessage);
            }
        }
        else {
            System.out.print("The recipient is non-existent in the contacts\n");
        }

    }
}