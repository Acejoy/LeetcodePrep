/*
the question link is: https://leetcode.com/problems/binary-tree-level-order-traversal/


using queue for level order traversal and keeping track of no. of current level nodes
and next level nodes.
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;
    vector<int> v;
    
    
    queue<TreeNode*> nodeQ;
    TreeNode* curNode;
    int nextLevelNodes=0, curLevelNodes=0;
    
    if(root){
        
        nextLevelNodes++;
        nodeQ.push(root);
    }
    
    while(!nodeQ.empty()){            
        
        if(curLevelNodes==0){
            curLevelNodes=nextLevelNodes;
            nextLevelNodes=0;
        }
        
        curNode=  nodeQ.front();
        nodeQ.pop();
        
        v.push_back(curNode->val);
        
        if(curNode->left!=NULL){
            nodeQ.push(curNode->left);
            nextLevelNodes++;
        }
        
        if(curNode->right!=NULL){
            nodeQ.push(curNode->right);
            nextLevelNodes++;
        }
        
        if(curLevelNodes==1){
            ans.push_back(v);
            v.clear();
        }           
        
        curLevelNodes--;
    }
    
    return ans;
}

void printvector(vector<vector<int>> v){
    for(auto e: v){
        for(auto x:e){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}

int main() { 

    TreeNode* root = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);

    root->left = two;
    root->right = three;
    three->left = four;
    three->right = five;
    

    vector<vector<int>> ans = levelOrder(root);
    printvector(ans);
    return 0;
}
