/*
The question link is : https://leetcode.com/problems/roman-to-integer/
*/

import java.util.Scanner;
import java.util.HashMap;

public class RomanToInteger{

    public static int RomanToInt( String romanNumber ) {
        HashMap<Character, Integer> m = new HashMap<>();

        m.put('I',1);
        m.put('V',5);
        m.put('X',10);
        m.put('L',50);
        m.put('C',100);
        m.put('D',500);
        m.put('M',1000);

        int sum = 0;
        //int prevIndex = -1;

        for(int i=0; i< romanNumber.length(); i++ ) {
            int curVal = m.get(romanNumber.charAt(i));
            
            if ( i!= 0 ){
                int prevVal = m.get(romanNumber.charAt(i-1));
                

                if( prevVal< curVal) {
                    sum -= prevVal;
                } else {
                    sum += prevVal;           
                }               
                 
            }
            
            if ( i == romanNumber.length() -1) {
                sum += curVal;
            }
             
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in) ;
        System.out.print("Enter The number :");

        String num = sc.next();
        System.out.println("the integer for roman numeral " + num + " is: "+ RomanToInt(num));
        
        sc.close();

    }
}