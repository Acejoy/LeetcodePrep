/*
Here we have to find kth smallest integer in BST.
We can simply get the inorder traversal in an array and return array[k-1](k is 1-indexed);
for efficiency, dont store it in an array, rather keep of count of inorder traversed nodes.
and then return curNode when count==k.
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

int kthSmallest(TreeNode* root, int k) {
    int numbersTraversed =0;
    TreeNode** ans = &root;
    
    inordertraversal(root, &numbersTraversed, ans, k);
    
    return (*ans)->val;
}

void inordertraversal(TreeNode* curNode, int* numbersTraversed, TreeNode** reqNode, int k) {
    if(!curNode) {
        return ;
    } else {
        inordertraversal(curNode->left, numbersTraversed, reqNode, k);
         (*numbersTraversed)++;
        
        if((*numbersTraversed) == k) {
            *reqNode = curNode;
            return;
        }
        
        inordertraversal(curNode->right, numbersTraversed, reqNode, k);
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

    cout<<kthSmallest(root, 1)<<'\n';
    return 0;
}