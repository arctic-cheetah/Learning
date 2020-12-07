import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    ArrayList<String> cars = new ArrayList<String>();
    Scanner scan = new Scanner(System.in);
    String c;
    System.out.println("Enter some cars: ");
    while (scan.hasNextLine()) {
        c = scan.nextLine();
        cars.add(c);
    }
    
    for (int i = 0; i < cars.size(); i +=1) {
        System.out.println(cars.get(i));
    }

    cars.clear();
    scan.close();
    }
}