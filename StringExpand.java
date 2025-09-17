/*  This program is used to extand characters in an input string with a perticular digit
    example. Input: "a1b4c3" 
             Output: "abbbbccc"

    Name - Shreepal Singh
    Date - 16/9/25
 */

import java.util.*;
public class StringExpand {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String inputString = "";
        try {
            System.out.print("Enter a string:");
            inputString = scan.nextLine();
            String extendedString = "";
            for(int i = 1; i < inputString.length(); i+=2) {
                if(inputString.charAt(i) >= '0' && inputString.charAt(i) <= '9') {
                    char lastChar = '\0';
                    if(i > 0)
                    lastChar = inputString.charAt(i-1);
                    int times = inputString.charAt(i) - '0';
                    for(int j = 0; j < times; j++) {
                        extendedString += lastChar;
                    }
                }
            }
            System.out.println("Extended String: " + extendedString);
        }
        catch(Exception e) {
            System.out.println("Please enter a valid input string:");
        }
    }
}
