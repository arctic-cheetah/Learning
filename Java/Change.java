import java.util.*;

public class Change{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter an integer number: ");
        int cash = input.nextInt();
        
        //Store all australian notes
        int notes[] = {100, 50, 20, 10, 5, 2, 1};
        
        //Print the number of notes given out:
        for (int x: notes){
            //this is basically the euclidean algorithm
            int num_notes = cash / x;
            cash = cash % x;
            System.out.println("Number of $"+x+" : "+num_notes);
        }

    }
}