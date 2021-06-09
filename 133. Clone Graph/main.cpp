/*
using bfs to clone graph
*/
#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


Node* cloneGraph(Node* node) {
    
    if(node==NULL){
        return NULL;
    }
    
    set<int> visited;
    queue<Node*> nodeQ;
    nodeQ.push(node);
    visited.insert(node->val);
    
    Node *curNode, *newNode, *newNeighborNode;
    map<int, Node*> nodeList;
    
    
    int index=0;
    while(!nodeQ.empty()){            
        curNode=nodeQ.front();
        nodeQ.pop();
        // cout<<"Current Node"<<curNode->val<<'\n';
        
        
        
        if(nodeList.find(curNode->val)!=nodeList.end()){
            newNode = nodeList[curNode->val];
        } else {
            newNode = new Node(curNode->val);
            nodeList.insert({curNode->val, newNode});    
        }
        
        //neighbors
        for(auto neighborNode: curNode->neighbors){
            if(nodeList.find(neighborNode->val)!=nodeList.end()){
                newNeighborNode = nodeList[neighborNode->val];
            } else {
                newNeighborNode = new Node(neighborNode->val);
                nodeList.insert({neighborNode->val, newNeighborNode});    
            }
            
            // cout<<"Adding "<<newNeighborNode->val<<" to "<<newNode->val<<'\n';
            newNode->neighbors.push_back(newNeighborNode);
            
            if(visited.find(neighborNode->val)==visited.end()){
                visited.insert(neighborNode->val);                    
                nodeQ.push(neighborNode);
            }
            
        }
        
        
    }
    
    return nodeList[1];
}

void printGraphBFS(Node* root){
    Node* curNode;
    set<int> visited;

    queue<Node*> nodeQ;
    nodeQ.push(root);
    visited.insert(root->val);

    while(!nodeQ.empty()){
        curNode = nodeQ.front();
        nodeQ.pop();

        cout<<curNode->val<<' ';

        for(auto neighbor: curNode->neighbors){
            if(visited.find(neighbor->val)==visited.end()){
                nodeQ.push(neighbor);
                visited.insert(neighbor->val);
            }
        }

    }

    cout<<'\n';
}

int main(){

    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);

    one->neighbors.push_back(two);
    one->neighbors.push_back(four);
    two->neighbors.push_back(one);
    two->neighbors.push_back(three);
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);
    four->neighbors.push_back(three);
    four->neighbors.push_back(one);

    printGraphBFS(one);

    Node* res = cloneGraph(one);

    printGraphBFS(res);
    return 0;
}