#include<bits/stdc++.h>

using namespace std;

int getSum(int a, int b) {

    unsigned int prev_xor;
    unsigned int a_xor_b = a;
    unsigned int a_carry_b = b;
            
    do {
        
        prev_xor = a_xor_b;
        a_xor_b = prev_xor ^ a_carry_b;
        a_carry_b = (prev_xor&a_carry_b)<<1;
    } while(a_carry_b);

    return (int)a_xor_b;

}

int main(){
    int a=-1;
    int b=1;

    cout<<getSum(a, b)<<'\n';
    return 0;
}