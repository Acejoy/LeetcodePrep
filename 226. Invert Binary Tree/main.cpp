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

TreeNode* invertTree(TreeNode* root) {
    if(root) {
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
    }

    return root;
}

void printTree(TreeNode* curNode){
    if(curNode!=NULL){
        cout<<curNode->val<<' ';
        printTree(curNode->left);
        printTree(curNode->right);
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

    printTree(root);
    cout<<'\n';

    root = invertTree(root);
    printTree(root);
    cout<<'\n'; 
    return 0;
}