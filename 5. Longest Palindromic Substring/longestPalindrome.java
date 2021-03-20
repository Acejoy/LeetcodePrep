/*
the question link is:https://leetcode.com/problems/longest-palindromic-substring/


*/
import java.util.Scanner;

public class longestPalindrome{

    static int resultLength = 1;
    static int resultStart = 0;

    public static String findLongestPalin(String str) {
        int strLength = str.length();
        if ( strLength < 2) {
            return str;
        } else {
            for (int idx=0; idx < strLength ;idx++) {
                checkPalindrome(str, idx, idx);
                checkPalindrome(str, idx, idx+1);
            }
            return str.substring( resultStart , resultStart + resultLength);
        }        
    }

    public static void checkPalindrome(String s, int startIdx, int endIdx) {

        while(startIdx>=0 && endIdx <s.length() && s.charAt(startIdx) == s.charAt(endIdx) ) {
            startIdx--;
            endIdx++;
        }

        if ( resultLength < (endIdx -startIdx -1 ) ) {
            resultLength = (endIdx -startIdx -1 );
            resultStart = startIdx +1;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.println("The longest palindrome for " + s + " is: " + findLongestPalin(s));
        sc.close();
    }
}