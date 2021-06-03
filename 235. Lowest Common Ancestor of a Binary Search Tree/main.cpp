/*
here we need to find LCA of 2 nodes.to simplify our task we use a new function where left parameter
refers to node with lower value.

If current node has val==p || val==q, then that is LCA
or else if curNode's val is >p's and <q's val, then it is LCA
or else if curNode's val >both(p's and q's) then LCA is in left subtree.
or else if curNode's val <both(p's and q's) then LCA is in right subtree.

we have some constraints like p and q have to exist in bst.
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

//function has p as lower value node and q as higher value node.
TreeNode* LCAhelperFn(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(root->val==p->val || root->val==q->val){
        return root;
    }
    
    if(root->val>p->val && root->val<q->val){
        return root;
    }
    
    if(root->val> p->val && root->val>q->val){
        return LCAhelperFn(root->left, p, q);
    }
    
    if(root->val< p->val && root->val<q->val){
        return LCAhelperFn(root->right, p, q);
    }
    
    return NULL;
    
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    if(p->val>q->val){
        return LCAhelperFn( root, q, p);
    } else {
        return LCAhelperFn( root,  p, q);
    }
    
}

int main() { 

    TreeNode* root = new TreeNode(3);
    TreeNode* two = new TreeNode(2);
    TreeNode* one = new TreeNode(1);
    TreeNode* four = new TreeNode(4);

    root->left = one;
    root->right = four;
    one->right = two;

    cout<<lowestCommonAncestor(root, two, four)<<'\n';
    return 0;
}