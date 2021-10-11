import java.util.*;

public class Pattern2 {

    //1,11,21,1112,3112,211213,312213,212223,.....
    //For each unique digit of the previous num:
    //(count of digits, the digit itself)
    public static void main (String arg[]) {
        System.out.print("Enter number of sequences: ");
        Scanner scanf = new Scanner(System.in);
        int num = scanf.nextInt();
        
        int start_num = 1;
        for (int i = 1; i <= num; i+=1) {
            //Calculating the digit
            System.out.print(start_num + ",");

            int j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

            int temp_expression = 0;
            int digit;
            //Go through each digit
            for (int x : j) {

                int count = 0;
                int temp = start_num;

                //Go through the digit
                while (temp != 0) {
                    digit = temp % 10;
                    temp = temp / 10;

                    //Match the digit
                    //and count the number of occurrences
                    if (digit == x) {
                        count +=1;
                    }
                }
                //Construct the expression, that holds the digit count and digit itself
                if (count > 0) {
                    temp_expression *= 10;
                    temp_expression += count;
                    temp_expression *= 10;
                    temp_expression += x;
                }
                
            }
            start_num = temp_expression;


        }
    } 

}



