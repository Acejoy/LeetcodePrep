#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v){
    for(auto e: v){
        cout<<e<<' ';
    }

    cout<<'\n';
}

void createGraph(int numCourses, vector<vector<int>>& prerequisites,
                 vector<vector<int>>& graph) {
    for (auto requirement : prerequisites) {
        graph[requirement[1]].push_back(requirement[0]);
    }
}

void DFS(vector<vector<int>>& graph, int curNode, int& time,
         vector<bool>& visited, vector<int>& dTimeToNode,
         vector<int>& nodeToDtime) {
    visited[curNode] = true;

    for (auto neighbor : graph[curNode]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, time, visited, dTimeToNode, nodeToDtime);
        }
    }

    nodeToDtime[curNode] = time;
    dTimeToNode[time++] = curNode;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses, vector<int>());
    createGraph(numCourses, prerequisites, adjList);

    // fill departure time of each node
    vector<bool> visited(numCourses, false);
    vector<int> departureTime(numCourses, -1);
    vector<int> nodeToDeparture(numCourses, -1);

    int curTime = 0;

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            DFS(adjList, i, curTime, visited, departureTime, nodeToDeparture);
        }
    }

    //check for cycle
    for(int i=0; i<adjList.size(); i++){
        for(auto neighbor: adjList[i]){
            if(nodeToDeparture[i]<nodeToDeparture[neighbor]){
                return {};
            }
        }
    }

    vector<int> ans;
    
    for(int i=departureTime.size()-1; i>=0; i--){
        if(departureTime[i]!=-1){
            ans.push_back(departureTime[i]);
        }
    }

    return ans;
}

int main() {
    int numCourses1 = 4;
    vector<vector<int>> req1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    int numCourses2 = 4;
    vector<vector<int>> req2 = {{0, 3}, {1, 0}, {2, 1}, {3, 2}};

    vector<int> res = findOrder(numCourses2, req2);
    printVector(res);
    return 0;
}