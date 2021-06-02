/*
the question link is: https://leetcode.com/problems/binary-tree-maximum-path-sum/

My solution(not that efficient):
I Take 2 vectors, one for a path that can be continued upwards and another
that that cant be continued upwards.I return both these values for each node.
I finally take max of both the paths and that is result.

first vector contains the curNode itself, curNode to left child tree continuous part and
curNode to right child tree continuous part.

second vector contains the path from left child tree which is continuous and not continous, 
the path from right child tree which is continuous and not continuous, and the  path from curNode 
as root with paths from continuous parts from both child trees.


I take max of each vector and return it.
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

int maxPathSum(TreeNode* root) {
    int* v = helperFn(root);
    
    return max(v[0], v[1]);
}

int* helperFn(TreeNode* root){
        
    vector<int> m;
    vector<int> n{root->val};
    int *c1, *c2;

    if(root->left!=NULL) {
        c1 = helperFn(root->left);
        m.push_back(c1[0]);
        m.push_back(c1[1]);
        n.push_back(root->val+c1[0]);
    }

    if(root->right!=NULL) {
        c2 = helperFn(root->right);
        m.push_back(c2[0]);
        m.push_back(c2[1]);
        n.push_back(root->val+c2[0]);
    }

    if(root->left!=NULL && root->right!=NULL) {
        m.push_back(root->val+ c1[0]+ c2[0]);
    }

    int connectedToRoot = INT_MIN;
    int notConnectedToRoot = INT_MIN;

    int maxTemp=INT_MIN;
    for(auto x: m){
        maxTemp = max(maxTemp, x);
    }

    notConnectedToRoot = maxTemp;


    maxTemp = INT_MIN;


    for(auto x: n){
        maxTemp = max(maxTemp, x);
    }

    connectedToRoot = maxTemp;
    int *arr = new int[2];
    arr[0] = connectedToRoot;
    arr[1] = notConnectedToRoot;
    return arr;
    
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
    
    cout<<maxPathSum(root)<<'\n'; 
    return 0;
}