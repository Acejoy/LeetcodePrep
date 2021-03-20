/*

the question link is: https://leetcode.com/problems/integer-to-roman/submissions/

*/
import java.util.Scanner;

public class integerToRoman {

    public static String intToRoman(int x) {
        StringBuilder sb = new StringBuilder();

        while (x>0) {
            if ( x >= 1000) {
                x -= 1000;
                sb.append("M");
            } else if ( x >= 900) {
                x -= 900;
                sb.append("CM");
            } else if ( x >= 500) {
                x -= 500;
                sb.append("D");
            } else if ( x >= 400) {
                x -= 400;
                sb.append("CD");
            } else if ( x >= 100) {
                x -= 100;
                sb.append("C");
            } else if ( x >= 90) {
                x -= 90;
                sb.append("XC");
            } else if ( x >= 50) {
                x -= 50;
                sb.append("L");
            } else if ( x >= 40) {
                x -= 40;
                sb.append("XL");
            } else if ( x >= 10) {
                x -= 10;
                sb.append("X");
            } else if ( x >= 9) {
                x -= 9;
                sb.append("IX");
            } else if ( x >= 5) {
                x -= 5;
                sb.append("V");
            } else if ( x >= 4) {
                x -= 4;
                sb.append("IV");
            } else {
                x -= 1;
                sb.append("I");
            }
        }


        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the integer:");
        int number = sc.nextInt();

        System.out.println("The roman numeral for" + number + " is: "+ intToRoman(number));
        sc.close();

    }
}