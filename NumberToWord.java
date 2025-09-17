
/*  This program is used to convert a input number to its word conversion
    example. Input: 51 
             Output: "fifty one" 

    Name - Shreepal Singh
    Date - 16/9/25
 */

import java.util.Scanner;
public class NumberToWord {
    public static void printTens(int index) {
        String []tens = {"Ten", "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        System.out.print(tens[index-1] + " ");
    }
    public static void printOnes(int index) {
        String []ones = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
        System.out.print(ones[index-1]);
    }
    public static void printOthers(int number) {
        String []others = {"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","NineTeen"};
        int index = (number % 10);
        System.out.println(others[index-1]);
    }

    public static void printNumber(int number) {
        // base case for 0 and 1000
        if(number == 0) {
            System.out.println("Zero");
            return ;
        }
        if(number == 1000) {
            System.out.println("One Thousand");
            return ;
        }

        int store[] = {0, 0, 0};
        int index = 0;
        int num = number;
        while(num > 0) {
            int rem = num % 10;
            store[index++] = rem;
            num = num / 10;
        }
        int i = 0, j = 2;
        while(i < j) {
            int temp = store[i];
            store[i] = store[j];
            store[j] = temp;
            i++;
            j--;
        }

        index = 0;
        while(index < 3) {
            // printing hundreds - 100,200,300,etc.
            if(index == 0 && store[index] != 0) {
                printOnes(store[index]);
                System.out.print(" Hundred ");
            }
            // printing number from 11-19
            if(index == 1 && store[index] == 1 && store[index+1] != 0) {
                printOthers(store[index+1]);
                return ;
            }
            // printing tens - 10,20,30,etc.
            if(index == 1 && store[index] != 0) {
                printTens(store[index]);
            }
            // printing single digit - 1,2,3,etc.
            if(index == 2 && store[index] != 0) {
                printOnes(store[index]);
            }
            index++;
        }
    }
    public static void takeInput() {
        Scanner scan = new Scanner(System.in);
        int number;
        try {
            System.out.print("Enter a number:");
            number = scan.nextInt();
            while(number < 0 || number > 1000) {
                System.out.println("Invalid number please enter again:");
                number = scan.nextInt();
            }
            printNumber(number);
        } catch (Exception e) {
            System.out.println("Invalid input please enter again:");
            takeInput();
        }
    }
    public static void main(String[] args){
        takeInput();
    }
}
