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