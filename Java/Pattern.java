import java.util.*;

public class Pattern {
    public static void main (String arg[]) {
        //Fetch user input
        Scanner scanf = new Scanner(System.in);
        int num = scanf.nextInt();

        for (int i = 1; i <= num; i+=1) {

            //Prints out a row
            int k = i;
            for (int j = 1; j <= i; j+=1) {
                //print 1,2
                if (j == 1 || j == 2) {
                    System.out.print(j);
                }
                //Reverse order from i down to 2
                else {
                    System.out.print(k);
                    k -=1;
                }
            }

            System.out.println();
        }
        scanf.close();
    }
}