import java.util.Scanner;
class LongestSubStringAlphabeticity {
    
    public static void main (String args[]) {
        Scanner scanf = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanf.nextLine();
        char c = s.charAt(0);
        int count = 1;
        int longest = 0;
        for (int i = 1; i < s.length(); i +=1) {
            if (c <= s.charAt(i)) {
                count +=1;
            }
            else {
                if (count > longest) {
                    longest = count; 
                }
                count = 1;
            }
            c = s.charAt(i);
        }
        if (count > longest) {
            longest = count;
        }   

        System.out.print("The longest substring in alphabetical order is: " + longest + "\n");
        scanf.close();
    }

}