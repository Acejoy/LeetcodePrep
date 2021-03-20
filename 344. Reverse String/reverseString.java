//the question linkk is:https://leetcode.com/problems/reverse-string/submissions/
import java.util.Scanner;

public class reverseString {

    //inplace
    public static String reverseMyString( String s) {
        //convert String to character Array
        char[] str = s.toCharArray();
        
        char temp;
        int i=0, stringSize = s.length();
        while ( i< (stringSize/2)) {
            temp = str[i];
            str[i] = str[stringSize - i -1];
            str[stringSize - i -1] = temp;

            i++;
        }

        return new String(str);

    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string:");
        String st = sc.next();
        sc.close();

        StringBuilder reversed = new StringBuilder();
        reversed.append(st);

        reversed = reversed.reverse();

        String revFunc = new String(st);        
        revFunc = reverseMyString(st);

        System.out.println(reversed + " " + revFunc + " " + st);         
        
    }
}