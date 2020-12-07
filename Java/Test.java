import java.util.Scanner;

public class Test {
    public void fullThrottle() {
        System.out.print("The vehicle is at maximum throttle!\n");
    }

    public void speed(int n) {
        System.out.print("The vehicle's speed is " + n + "kph\n");
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a speed: ");
        int n = scan.nextInt();

        Test obj1 = new Test();
        obj1.fullThrottle();
        obj1.speed(n);
        scan.close();
    }
}