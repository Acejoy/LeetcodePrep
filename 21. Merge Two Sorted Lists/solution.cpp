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

void merge(ListNode** l1, ListNode** l2) {

    ListNode** head = l1 ;
    ListNode* prev=NULL;
    ListNode *i, *j;
    i = *l1;
    j = *l2;

    while((i!=NULL) && (j!=NULL)) {
        if(i->val < j->val) {
            if(prev==NULL) {
                *head = i;
            } else {
                prev->next = i;
            }

            prev = i;
            i = i->next;    
        } else {
            if(prev==NULL) {
                *head = j;
            } else {
                prev->next = j;
            }
            prev = j;
            j = j->next;
        }           
    }

    while(i!=NULL) {
        if(prev==NULL) {
            *head = i;
        } else {
            prev->next = i;
        }

        prev = i;
        i = i->next; 
    }

    while(j!=NULL) {
        if(prev==NULL) {
            *head = j;
        } else {
            prev->next = j;
        }

        prev = j;
        j = j->next; 
    } 
}

int main() {

	vector<ListNode*> lists;

	int n=2;
	//cout<<"Enter the number of lists:";
	//cin>>n;

	for(int i=0; i<n; i++) {
		int s, num;
		cout<<"enter size of list:";
		cin>>s;

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

		lists.push_back(head);
	}

	for(int i=0; i<n; i++) {
		printLists(lists[i]);
	}

	merge(&lists[0], &lists[1]);

	printLists(lists[0]);


	return 0;
}