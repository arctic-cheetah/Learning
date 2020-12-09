import java.util.Scanner;

class HowManyTimes {

    public static void main (String args[]) {
        System.out.print("Enter a string: ");
        Scanner scanf = new Scanner(System.in);
        String s = scanf.nextLine();

        System.out.print("Enter a character to count: ");
        String c = scanf.nextLine();

        int count = 0;
        for (int i = 0; i < s.length(); i +=1) {
            if (c.charAt(0) == s.charAt(i)) {
                count +=1;
            }
        }

        System.out.print("There were " + count + " occurrences of" + s + "\n");
        scanf.close();
    }

}