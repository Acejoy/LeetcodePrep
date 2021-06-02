/*
the question link is: https://leetcode.com/problems/binary-tree-maximum-path-sum/

So repeating numbers is allowed
So use 2 functions:
1. actual isSubtree fn for finding the starting point in main tree matching to root of subtree
2. isEqual fn: for calculating whether the tree rooted at root1 and root2 are equal.
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

bool isEqual(TreeNode* root1, TreeNode* root2){
    if(root1==NULL && root2==NULL) {
        return true;
        
    } else if(root1!=NULL && root2!=NULL) {
        
        return ((root1->val)==(root2->val)) && isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
        
    } else {
        
        return false;
        
    }
}


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
    if(subRoot==NULL){
        return true;
    }
    
    if(root!=NULL && subRoot!=NULL){
        
        if(isEqual(root, subRoot)){
            return  true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
    
    return false;        
}
    

int main() { 

    TreeNode* root = new TreeNode(1);
    TreeNode* one = new TreeNode(1);
    
    TreeNode* root2 = new TreeNode(1);

    root->left = one;
    
    cout<<isSubtree(root, root2)<<'\n'; 
    return 0;
}