#include<bits/stdc++.h>

using namespace std;

struct TreeNode {

 	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printArray(vector<int> &arr) {
	for(int i=0; i<arr.size(); i++) {
		cout<<arr[i]<<' ';
	}
	cout<<endl;
}
vector<int> merge(vector<int> &v1, vector<int> &v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> v3(n1+n2,0);
    
    //entering alements of v1 into v2;
    // for(int i=0; i<n1; i++) {
    //     v2.push_back(v1[i]);
    // }
    
    int i=0, j=0, k=0;
    
    while(i<n1 && j<n2) {
        if(v1[i]<v2[j]){
            v3[k++] = v1[i++];
        } else {
            v3[k++] = v2[j++];
        }
    }
    
    while(i<n1){
        v3[k++] = v1[i++];
    }
    
    while(j<n2){
        v3[k++] = v2[j++];
    }
    
    return v3;
    
}
void getList(TreeNode* root, vector<int> &v) {
    if(root) {
        getList(root->left, v);
        v.push_back(root->val);
        getList(root->right, v);
    }
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    
    vector<int> list1, list2;
    getList(root1, list1);
    getList(root2, list2);
    
    vector<int> ans = merge(list1, list2);
    
    return ans;
    
}

int main() {

	//tree1 with 1,2,4
	TreeNode* left1 = new TreeNode(1);
	TreeNode* right1 = new TreeNode(4);
	TreeNode* root1 = new TreeNode(2, left1, right1);

	//tree2 with 0,1,3
	TreeNode* left2 = new TreeNode(0);
	TreeNode* right2 = new TreeNode(3);
	TreeNode* root2 = new TreeNode(1, left2, right2);

	vector<int> ans = getAllElements(root1, root2);
	printArray(ans);

	return 0;
}