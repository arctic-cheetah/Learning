//A program that performs a caesar shift
import java.util.Scanner;

class Caesar {
    //A helper function to shift the character's by some number
    static String caesar (int shift, char s[], int len) {
        for (int i = 0; i < len; i +=1) {
            if(s[i] != ' ') {
                int temp = (int)s[i] - 'a' + shift;
                char temp2 = (char)((temp % 26) + 'a');
                s[i] = temp2;
            }
        }
        return new String(s);
    }
    public static void main (String args[]) {
        System.out.print("Enter a string: ");
        Scanner scanf = new Scanner(System.in);
        String s = scanf.nextLine();
        
        for (int i = 0; i < 26; i +=1) {
            char temp[] = s.toCharArray();
            System.out.print(i + " Result: " + caesar(i, temp, s.length()) + "\n");
        }
        scanf.close();
    }
}