#include<iostream>
#include<vector>
#include<cmath>
#include<utility>

using namespace std;

void printVec(vector<pair<int, char>> v) {
    for(auto e:v) {
        cout<<"======>"<<e.first<<' '<<e.second<<endl;
    }
}

int main(int argc, char *a[])
{
    //Write code here
    int n;
    cin>>n;

    while(n--) {
        int lowerLimit, upperLimit;
        cin>>lowerLimit;
        cin>>upperLimit;

        vector<pair<int, char>> m;
        for(int i=lowerLimit; i<=upperLimit; i++) {
            if(i==2 || i%2!=0) {
                m.push_back(make_pair(i, 'O'));
            }
        }       

        int maxFactor = (int) sqrt(upperLimit);

        for(int i=3; i<=maxFactor; i+=2) {
            for(int j=0; j<m.size(); j++) {
                if(m[j].second && ((m[j].first)%i==0) && ((m[j].first)>=i*i)) {
                    m[j].second='X';
                }
            }
        }

        //printVec(m);

        /*counting primes left*/
        int count=0;
        for(auto e:m) {
            if(e.second=='O') {
                count++;
            }
        }

        if(count==0) {
            cout<<"-1"<<endl;
            continue;
        }

        if(count==1) {
            cout<<"0"<<endl;
            continue;
        }

        /*min prime*/
        int minPrime;
        for(int i=0; i<m.size(); i++) {
            if(m[i].second=='O'){
                minPrime =m[i].first;
                break;
            }
        }

        /*max prime*/
        int maxPrime;
        for(int i=m.size()-1; i>=0; i--) {
            if(m[i].second=='O'){
                maxPrime =m[i].first;
                break;
            }
        }

        cout<<(maxPrime-minPrime)<<endl;
    }
}