/*
here we are using two pointer for lower and right limits for the current node.
We are not using INT_MIN and IMT_MAX to remove its dependency.
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


bool  checkValidityHelper(TreeNode* root, TreeNode* leftLimit, TreeNode* rightLimit) {
    if(root==NULL){
        return true;
    } 
    
    if(leftLimit!=NULL && root->val<=leftLimit->val) {
        return false;
    }
    
    if(rightLimit!=NULL && root->val>=rightLimit->val) {
        return false;
    }
    
    return checkValidityHelper(root->left, leftLimit, root ) && checkValidityHelper(root->right, root, rightLimit);
    
}

bool isValidBST(TreeNode* root) {
    return checkValidityHelper(root, NULL, NULL);
    
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

    cout<<isValidBST(root)<<'\n';
    return 0;
}