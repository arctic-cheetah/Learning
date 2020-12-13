import java.util.HashSet;
import java.util.Scanner;
import java.util.Iterator;
//import java.util.function.Consumer;

public class Test2 {
    static void print_set(HashSet<Integer> newSet) {
        Iterator<Integer> it = newSet.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
        System.out.print("\n");
    }

    public static void main (String[] args) {
        HashSet<Integer> newSet = new HashSet<Integer>();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a set of numbers: ");
        Integer i = 0;
        while (scan.hasNextInt()) {
            i = scan.nextInt();
            newSet.add(i);
        }

        System.out.print("Using an iterator\n");
        Iterator<Integer> it = newSet.iterator();
        //Loop through the hashSet
        print_set(newSet);

        System.out.print("Removing items less than 10 \n");
        while (it.hasNext()) {
            i = it.next();
            if (i < 10) {
                it.remove();
            }
        }

        System.out.print("Adding all numbers by 1\n");


        print_set(newSet);
        
        scan.close();
    }
}