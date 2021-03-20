/*the link to question:https://leetcode.com/problems/fizz-buzz/
the pseudo code is :

for i = 1 to N:
    if i mod 15 == 0 :
        print"FizzBuzz"
    else if i mod 3 == 0 :
        print"Fizz"
    else if i mod 5 == 0 :
        print"Buzz"
    else :
        print i
end
*/

#include<iostream>

using namespace std;

int main() {

    int n;
    cout<<"Enter the number:";
    cin>>n;

    for( int i=1; i<=n; i++) {
        if ( i%15 == 0 ) {
            cout<<"FIzzBuzz"<<endl;
        } else if ( i%3 == 0 ) {
            cout<<"Fizz"<<endl;
        } else if ( i%5 == 0 ) {
            cout<<"Buzz"<<endl;
        } else {
            cout<<i<<endl;
        }
    }

    return 0;
}