// So here we have to find the min no of refuelings required.
// THis cant be done greedily.If the current fuel cant reach the destination, we need to refuel
// using the maximum value of gas present in a gas station (only those gas stations that can be reached
// from curPos with current Fuel left or have alredy been passed can be used for refueling)
// So we use priority queue to keep track of max gas values(using greedy approach here, since this
// approach minimises the no of refuels reqd and the gas tank of car has inifinite capacity)
// that are traversed.Each time the next gas station/target can't be reached from current position
// we refuel using top of priority queue.

// If finally the destination can be reached we output the count of refuels, else -1.
#include<bits/stdc++.h>

using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> que;
    int curFuel=startFuel;
    int res=0;
    for (auto& s:stations) {
        while (curFuel<s[0] && !que.empty()) {
            curFuel+=que.top();
            que.pop();
            res++;
        }
        if (curFuel<s[0]) return -1;
        que.push(s[1]);
    }
    
    while (curFuel<target && !que.empty()) {
        curFuel+=que.top();
        que.pop();
        res++;
    }
    if (curFuel<target) return -1;
    return res;
}

int main(){

    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    int dest = 100;
    int startFuel = 10;
    cout<<minRefuelStops(dest, startFuel, stations)<<'\n';
    return 0;
}