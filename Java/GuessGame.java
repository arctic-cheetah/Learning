//A game where the user must guess a number in less than 5 tries.
//
import java.util.Scanner;
import java.util.Random;

class GuessGame {

    public static void main (String args[]) {
        Scanner scanf = new Scanner(System.in);
        //Ask the user's name
        System.out.print("Enter a name: ");
        String userName = scanf.nextLine();

        //Greet the user
        System.out.print("G'day " + userName + "\n");

        //Ask to begin the game
        System.out.print("Enter any key to begin the game...\n");
        scanf.nextLine();

        //Generate a random number
        Random rnNum = new Random();
        int num = rnNum.nextInt(20);

        //Track the number of attempts
        int count = 0;
        int guess = 0;
        boolean win = false;

        do {
            if (count > 0 && guess < num) {
                System.out.print("Guess higher\n");
            }
            else if (count > 0 && guess > num) {
                System.out.print("Guess lower\n");
            }
            System.out.print("Enter a number: ");
            guess = scanf.nextInt();
            if (guess == num) {
                win = true;
            }
            count +=1;
        }
        while (count < 5 && !win);

        if (win) {
            System.out.print("Congratulations " + userName + " you win! The number was " + num + "\n");
        }
        else {
            System.out.print("You lost! The number was " + num + "\n");
        }
        scanf.close();
    }

}



