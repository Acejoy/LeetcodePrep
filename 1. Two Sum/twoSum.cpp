/*the question link is :https://leetcode.com/problems/two-sum/

the pseudocode:

Approach 1(Brute Force):
    for i=1 to n-1:
        for j=i+1 to n:
            if ar[i] + ar[j] == target:
                return i,j

Approach 2(One Hash Table with two passes) :

    1. create a hash table and enter the elements
    2. loop through the array :
        for i=1 to n:
            search for (target - arr[i]) in the hash table.if found, find the index of the (target - arr[i]) and return i and that index.

Approach 3(One Hash Table with one pass) :

    1. create a hash table 
    2. loop through the array :
        for i=1 to n:
            search for (target - arr[i]) in the hash table.if found, find the index of the (target - arr[i]) using the other hash table and return i and that index.
            if not found enter it into the hash table.


*/

#include<bits/stdc++.h>

using namespace std;

pair<int, int> approach1( vector<int>& v, int target ) {
    pair<int, int> p;

    for( int i=0; i<v.size()-1; i++ ) {
        for ( int j= i+1; j<v.size(); j++ ) {
            if ( v[i] + v[j] == target ) {
                p.first = i;
                p.second = j;

                return p;
            }
        }
    }

    return make_pair(-1, -1);

}

pair<int, int> approach2( vector<int>& v, int target ) {
    
    pair<int, int> p;
    map<int, int> m;

    for(int i=0; i<v.size(); i++) {
        m.insert(make_pair(v[i], i));
    }

    for(int i=0; i<v.size()-1; i++) {
        map<int, int>::iterator it = m.find(target - v[i] );

        if( it != m.end() && (it->second != i )) {
            p.first = i;
            p.second = it->second;

            return p;
        }
    }

    return make_pair(-1, -1);
}

pair<int, int> approach3(vector<int>& v, int target) {

    map<int, int> m;
    pair<int, int> p;

    for( int i=0; i<v.size(); i++ ) {

        map<int, int>::iterator it = m.find(target - v[i]);

        if( it != m.end() ) {
            p.first = it->second;
            p.second = i;

            return p;
        } else {
            m.insert(make_pair(v[i], i));
        }
        
    }


    return make_pair(-1, -1);
}

int main() {

    vector<int> arr = {3,3};
    int target = 6;

    pair<int, int> answer1 = approach1(arr, target);
    pair<int, int> answer2 = approach2(arr, target);
    pair<int, int> answer3 = approach3(arr, target);

    cout<<answer1.first<<" "<<answer1.second<<endl;
    cout<<answer2.first<<" "<<answer2.second<<endl;
    cout<<answer3.first<<" "<<answer3.second<<endl;

    return 0;
}