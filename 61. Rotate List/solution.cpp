#include<bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLists(ListNode* head) {
	while(head!=NULL) {
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

ListNode* rotateRight(ListNode* head, int k) {
    
    ListNode *curNode, *prev=NULL, *lastNode, *newLastNode, *newHead;
    int totalNodes=0, nodesTraversed=0;
    
    if(!head || !(head->next)) {
        return head;
    }
    
    curNode=head;
    while(curNode != NULL) {
        totalNodes++;
        prev = curNode;
        curNode = curNode->next;
    }
    
    lastNode = prev;
    prev=NULL;
    curNode=head;
    
    while(curNode != NULL) {
        if((nodesTraversed+k)%totalNodes == 0) {
            newHead = curNode;
            break;
        }
        
        prev = curNode;
        nodesTraversed++;
        curNode = curNode->next;
    }
    
    newLastNode = prev;
    
    if(newLastNode!=NULL){
        newLastNode->next = NULL;
        lastNode->next = head;
    }       
    
    return newHead;
    
}

int main() {

	
	int s, num, k;
	cout<<"enter size of list:";
	cin>>s;
	cout<<"enter k:";
	cin>>k;

	ListNode *head = NULL, *cur ;

	for(int i=0; i<s; i++) {
		cin>>num;
		ListNode* node = new ListNode(num);

		if(head==NULL){
			head = node;
		} else {
			cur->next = node;
		}
		cur = node;
	}
	
	cur->next = NULL;

	printLists(head);

	ListNode* newHead = rotateRight(head, k);
	
	printLists(newHead);


	return 0;
}