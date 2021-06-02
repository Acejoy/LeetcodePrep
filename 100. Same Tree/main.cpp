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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL && q==NULL){
        return true;
    } else if(p!=NULL && q!=NULL) {
        bool valEQ = (p->val==q->val);
        return valEQ && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
        return false;
    }   
}

int main() { 

    TreeNode* rootA = new TreeNode(1);
    TreeNode* twoA = new TreeNode(2);
    TreeNode* threeA = new TreeNode(3);
    
    rootA->left = twoA;
    rootA->right = threeA;
    
    TreeNode* rootB = new TreeNode(1);
    TreeNode* twoB = new TreeNode(2);
    TreeNode* threeB = new TreeNode(3);
    
    rootB->left = twoB;
    rootB->right = threeB;
    
    
    cout<<isSameTree(rootA, rootB)<<'\n';
    return 0;
}