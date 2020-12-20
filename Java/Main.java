//A silly program that asks a user to change the status of a patient
//in surgery
import java.util.Scanner;

class Main {
    static String le = "Left eye";
    static String re = "Right eye";
    static String ht = "Heart";
    static String st = "Stomach";
    static String sk = "Skin";

    public static void main (String args[]) {
        Scanner scanf = new Scanner(System.in);
        //Fetch the name and age of the patient
        System.out.println("Enter the name of the patient: ");
        String name = scanf.nextLine();

        System.out.println("Enter the age of the patient: ");
        //int age = scanf.nextInt();

        LeftEye leftEye = new LeftEye(le, "Healthy", "Violet");
        RightEye rightEye = new RightEye(re, "Healthy", "Violet");
        Heart heart = new Heart(ht, "CHD", 75);
        Stomach stomach = new Stomach(st, "Healthy", "Hungry");
        //Skin skin = new Skin(sk, "Vertiligo");
        boolean quit = false;

        do {
            System.out.println("Select an organ: ");
            System.out.println("1." + le);
            System.out.println("2." + re);
            System.out.println("3." + ht);
            System.out.println("4." + st);
            System.out.println("5." + sk);
            System.out.println("6. Quit");

            int entry = scanf.nextInt();
            scanf.nextLine();
            if (entry == 1) {
                System.out.println("Enter an action: ");
                String action = scanf.nextLine();
                leftEye.setAction(action);
                System.out.println(name + "'s " + "left eye was " + action);
            }
            else if (entry == 2) {
                System.out.println("Enter an action: ");
                String action = scanf.nextLine();
                rightEye.setAction(action);
                System.out.println(name + "'s " + "right eye was " + action);
            }
            else if (entry == 3) {
                System.out.println("Enter a heart pace: ");
                int heartRate = scanf.nextInt();
                heart.setHeartRate(heartRate);
                System.out.println(name + "'s " + "heart pace is now " + heartRate);
            }
            else if (entry == 4) {
                System.out.println("Enter a status");
                String status = scanf.nextLine();
                stomach.setStatus(status);
                System.out.println(name + "'s " + "heart pace is now " + status);
            }
            else if (entry == 6) {
                System.out.print("Session exited\n");
                quit = true;
            }

        }
        //Prompt the user to select an organ 
        while (!quit);


        scanf.close();

    }
} 