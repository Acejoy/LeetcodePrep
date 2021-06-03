/*
the question link is: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
we are looking at preorder and inorder vectors. for each element in preorder we are finding
it in inorder vector and defining the limits for its leftchild and rightchild.
recursively we are agin finding the root node of left and right child subtree 
and defining its children's limits.

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

vector<int> preorderObj;
vector<int> inorderObj;
map<int, int> valToIdx;

void setValMap() {
    for(int i=0; i<inorderObj.size(); i++){
        valToIdx.insert({inorderObj[i], i});
    }        
}

void printMap() {
    for(auto e:valToIdx){
        cout<<e.first<<' '<<e.second<<'\n';
    }

    cout<<'\n';
}

bool withinRange(int leftLimit, int rightLimit, int idx) {
    

    if(leftLimit<0 || rightLimit>=preorderObj.size() || leftLimit>rightLimit) {
        return false;
    }

    int val = preorderObj[idx];
    int foundIdx = valToIdx[val];   

    if(foundIdx>=leftLimit && foundIdx<=rightLimit){
        return true;
    } else {
        return false;
    }
}

TreeNode* buildTreeHelper(int leftLimit, int rightLimit, int* preorderIdx){

    int curVal = preorderObj[*preorderIdx];

    if(leftLimit>rightLimit) {
        return NULL;            
    } else if(leftLimit==rightLimit) {
        cout<<"1.Created node...."<<curVal;
        cout<<" with leftLimit:"<<leftLimit<<" and rightLimit:"<<rightLimit<<'\n';
        TreeNode* node = new TreeNode(curVal);
        return node;
    } else {
       
        cout<<"2.Created node...."<<curVal;
        cout<<" with leftLimit:"<<leftLimit<<" and rightLimit:"<<rightLimit<<'\n';
        
        TreeNode* curNode = new TreeNode(curVal);
        
        int inorderIdx = valToIdx[curVal];

        bool r = withinRange(leftLimit, inorderIdx-1, *preorderIdx +1);
        if(r){
            *preorderIdx += 1;            
            TreeNode* leftChild = buildTreeHelper(leftLimit, inorderIdx-1, preorderIdx);
            curNode->left = leftChild;
        }

        r = withinRange(inorderIdx+1, rightLimit, *preorderIdx +1);
        if(r){
            *preorderIdx += 1;            
            TreeNode* rightChild = buildTreeHelper(inorderIdx+1, rightLimit, preorderIdx);
            curNode->right = rightChild;
        }

        return curNode;
    }
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preorderObj = preorder;
    inorderObj = inorder;
    
    int numNodes = preorder.size();
    int idx = 0;
    
    setValMap();
    printMap();
    
    return buildTreeHelper(0, numNodes-1, &idx); 
}

int main() { 

    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};

    buildTree(preorder, inorder);

    return 0;
}