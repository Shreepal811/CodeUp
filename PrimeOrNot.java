
/*  This program is used to check whether a input number is a prime number or not
    example. Input: 21 
             Output: "The given number is NOT prime" 

    Name - Shreepal Singh
    Date - 16/9/25
 */

import java.util.*;
 
public class PrimeOrNot {
    public static boolean isPrime(int number) {
        if(number <= 1) return false;
        for(int i = 2; i < number; i++) {
            if(number % i == 0) return false;
        }
        return true;
    }
    public static void takeInput() {
        Scanner scan = new Scanner(System.in);
        int number;
        try {
            System.out.print("Enter a number:");
            number = scan.nextInt();
            if(isPrime(number)) {
                System.out.println("The given number is a prime number");
            }
            else {
                System.out.println("The given number is not a prime number");
            }
        }
        catch(Exception e) {
            System.out.println("Input is not a valid number! please enter again:");
            takeInput();
        }
    }
    public static void main(String[] args) {
        takeInput();
    }
}
