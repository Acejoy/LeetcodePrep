/*
the question link is: https://leetcode.com/problems/binary-tree-maximum-path-sum/

so the maximum path can be of 3 types:
1.curNode is part of path , and path extends above .
2.curNode is part of path and curNode is root of the path.
3.curNode is not part of path.

so we have 3 variables:
1- taking care of the path from left and right child tree to curNode
2- taking care of the path with curNode as root
3- the final result

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
        
    int r = INT_MIN;
    
    maxPathHelper(root, &r);
    
    return r;
}

int maxPathHelper(TreeNode* root, int* Result){
    if(root==NULL){            
        return 0;
    } else {
        
        int leftmax = maxPathHelper(root->left, Result);
        int rightmax = maxPathHelper(root->right, Result);
        
        int continousPath = max(max(leftmax, rightmax)+ root->val, root->val);
        
        int pathCurRoot = max(continousPath, root->val+leftmax + rightmax);
        
        *Result = max(*Result, pathCurRoot);
        
        return continousPath;
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
    
    cout<<maxPathSum(root)<<'\n'; 
    return 0;
}

