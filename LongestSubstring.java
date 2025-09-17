
/*  This program is used to print the length of longest substring without repeating characters
    example. input: s = "abcabcbb" 
             Output: 3 

    Name - Shreepal Singh
    Date - 16/9/25
 */

import java.util.*;
public class LongestSubstring {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a string:");
        String inputString = scan.nextLine();
        HashMap <Character, Integer> map = new HashMap<>();

        int maxLength = 0;
        int left = 0, right = 0;
        while(right < inputString.length()) {
            char currCharacter = inputString.charAt(right);
            if(map.containsKey(currCharacter)) {
                left = map.get(currCharacter) + 1;
            }
            map.put(currCharacter, right);
            int length = right-left + 1;
            maxLength = Math.max(maxLength, length);
            right++;
        }
        System.out.println("lenght of longest substring without repeating characters: " + maxLength);
    }
}
