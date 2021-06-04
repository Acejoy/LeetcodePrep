/*
here a list of stocks is given, a buy date and sell date after buy date is reqd to find max profit
let the first element be minElement, as you traverse vector, find the min ELement,
then wou will find the max difference.
*/
#include<bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minElement = prices[0];
    
    for(int i=1; i<prices.size(); i++) {
        maxProfit = max(prices[i] - minElement, maxProfit);            
        if(prices[i]<minElement) {
            minElement = prices[i];
        }
    }
    
    return maxProfit;
}

int main() {

    vector<int> stocks = {7,1,5,3,6,4};
    cout<<maxProfit(stocks)<<'\n';

    return 0;
}