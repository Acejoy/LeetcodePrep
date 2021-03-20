/*
the link to question is :https://leetcode.com/problems/reverse-integer/
Given a 32-bit signed integer, reverse digits of an integer

*/

#include<bits/stdc++.h>

using namespace std;

#define maxVal 2147483647
#define minVal -2147483648

int reverse(int x) {

    bool flag = false;
    long long int reverseInt = 0, num = x, rem;
        
    if ( num> 0) {
        flag = false;
    } else {
        num*= -1;
        flag = true;
    }

        

    while(num) {
        reverseInt = reverseInt*10 + (num%10);
        num/=10;
    }

    if (flag) {
        reverseInt*=-1;
    }    

    if ( (reverseInt > maxVal) || (reverseInt < minVal)) {
        return 0;
    } else {
        return (int) reverseInt;
    }


}

int main(){

    
    int n1=1534236469;
    int n2= -1534236469;
    cout<<reverse(n1)<<endl;
    cout<<reverse(n2)<<endl;

    return 0;
}