#include<bits/stdc++.h>

using namespace std;
class Node{
  public:
    int val;
    vector<int> adjList;
    
    Node(int _val){
        val = _val;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node> graph;
        
        for(int i=0; i<numCourses; i++){
            graph.push_back(Node(i));
        }
        
        //adjacency Lists
        for(auto dependency: prerequisites){
            //checking for self cycles
            if(dependency[1]==dependency[0]){
                return false;
            }
            graph[dependency[1]].adjList.push_back(dependency[0]);
        }
        
        return isDAG(graph);
        
    }
    
    void DFS(vector<Node>& Graph, vector<bool>& visited, vector<int>& departure, int idx, int& time){
        visited[idx]=true;
        for(auto e: Graph[idx].adjList){
            if(!visited[e]){                
                DFS(Graph, visited, departure, e, time);
            }
        }
        
        departure[idx]=time++;
    }
    
    bool isDAG(vector<Node>& Graph){
        int time=0;
        vector<int> departureTime(Graph.size(), 0);
        vector<bool> visited(Graph.size(), false);
        
        
        for(int i=0; i<Graph.size(); i++){
            if(!visited[i]){
                DFS(Graph, visited, departureTime, i, time);
            }
        }
        
        
        for(int i=0; i<Graph.size(); i++){
            for(auto neighbor: Graph[i].adjList){
                if(departureTime[i]<departureTime[neighbor]){
                    return false;
                }
            }
        }
        
        return true;
    }
};


int main(){
    Solution s = Solution();
    vector<vector<int>> req = {{1,0},{0,1}};
    int numCourses = 2;
    cout<<s.canFinish(numCourses, req)<<'\n';
    return 0;
}