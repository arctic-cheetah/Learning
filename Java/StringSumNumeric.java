import java.util.Scanner;

class StringSumNumeric {
    static boolean isNumeric(char c) {
        if ('0' <= c && c <= '9') {
            return true;
        }
        return false;
    }
    public static void main (String args[]) {
        System.out.print("Enter a string\n");
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int len = s.length();
        int sum = 0;
        char c = 0;
        for (int i = 0; i < len; i +=1) {
            c = s.charAt(i);
            if (isNumeric(c)) {
                sum += (c - '0');
            }
        }
        System.out.println(sum);
        scan.close();
    }
}