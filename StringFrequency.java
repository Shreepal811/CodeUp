
/*  This program is used to print Frequency of a character from a input string
    example. Input: "aabcccdeee" 
             Output: "a2b1c3d1e3"

    Name - Shreepal Singh
    Date - 16/9/25
 */
import java.util.*;
public class StringFrequency {
    static void characterFrequency(String inpuString) {
        int index = 0;
        String charFreqString = "";
        while(index < inpuString.length()) {
            char currentCharacter = inpuString.charAt(index);
            int occurance = 0;
            while(index < inpuString.length() && inpuString.charAt(index) == currentCharacter) {
                index++;
                occurance++;
            }
            charFreqString += currentCharacter;
            charFreqString += (occurance);
        }
        System.out.println("characters with their frequencies: " + charFreqString);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String inputString = "";
        try {
            System.out.print("Enter a string:");
            inputString = scan.nextLine();
            characterFrequency(inputString);
        }
        catch(Exception e) {
            System.out.println("Invalid input");
        }
    }
}
