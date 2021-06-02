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

string serialize(TreeNode* root) {
    stringstream serialisedTree;
    queue<TreeNode*> nodeQ;

    TreeNode* curNode;
    nodeQ.push(root);

    while (!nodeQ.empty()) {
        curNode = nodeQ.front();
        nodeQ.pop();

        if (curNode != root) {
            serialisedTree << ' ';
        }

        if (curNode != NULL) {
            serialisedTree << (curNode->val);
            nodeQ.push(curNode->left);
            nodeQ.push(curNode->right);
        } else {
            serialisedTree << "null";
        }
    }

    return serialisedTree.str();
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    stringstream dataStream;

    dataStream << data;

    string curStr;

    TreeNode *root, *curNode, *leftChild, *rightChild;
    queue<TreeNode*> nodeQ;

    dataStream >> curStr;

    if (curStr == "null") {
        root = NULL;
    } else {
        root = new TreeNode(stoi(curStr));
        nodeQ.push(root);
    }

    while (!nodeQ.empty()) {
        curNode = nodeQ.front();
        nodeQ.pop();

        // left child
        dataStream >> curStr;
        if (curStr == "null") {
            curNode->left = NULL;
        } else {
            leftChild = new TreeNode(stoi(curStr));
            nodeQ.push(leftChild);
            curNode->left = leftChild;
        }

        // right child
        dataStream >> curStr;
        if (curStr == "null") {
            curNode->right = NULL;
        } else {
            rightChild = new TreeNode(stoi(curStr));
            nodeQ.push(rightChild);
            curNode->right = rightChild;
        }
    }

    return root;
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

    string serialised = serialize(root);
    cout<<serialised<<'\n'; 
    return 0;
}