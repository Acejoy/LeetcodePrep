#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v){
    for(auto e: v){
        cout<<e<<' ';
    }

    cout<<'\n';
}


void createGraph(int numCourses, vector<vector<int>>& prerequisites,
                 vector<vector<int>>& graph, vector<int>& inDegree) {
    for (auto requirement : prerequisites) {
        graph[requirement[1]].push_back(requirement[0]);
        inDegree[requirement[0]]++;
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<bool> visited(numCourses, false);
    queue<int> nodeQ;

    vector<vector<int>> adjList(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    createGraph(numCourses, prerequisites, adjList, indegree);

    //check for cycle
    //if no node's indegree=0 then cycle present.
    int startIdx;
    bool cyclePresent = true;
    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]==0){
            startIdx = i;
            cyclePresent=false;
            nodeQ.push(startIdx);
            visited[i]=true;
        }
    }

    if(cyclePresent){
        return {};
    }

    //traversal to find topological sorting
    int curIdx;
    vector<int> ans;    
    

    while(!nodeQ.empty()){
        curIdx = nodeQ.front();
        nodeQ.pop();

        ans.push_back(curIdx);

        for(auto e: adjList[curIdx]){
            if(!visited[e]){
                
                indegree[e]--;
                if(indegree[e]==0){
                    nodeQ.push(e);
                    visited[e]=true;
                }
            }
        }
    }

    if(ans.size()==numCourses){
        return ans;
    } else {
        return {};
    }
}

int main(){

    int numCourses1 = 4;
    vector<vector<int>> req1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    int numCourses2 = 4;
    vector<vector<int>> req2 = {{0, 3}, {1, 0}, {2, 1}, {3, 2}};

    int numCourses3 = 5;
    vector<vector<int>> req3 = {{0, 3}, {1, 0}, {2, 1}, {3, 2}, {0, 5}};

    vector<int> res = findOrder(numCourses3, req3);
    printVector(res);

    return 0;
}