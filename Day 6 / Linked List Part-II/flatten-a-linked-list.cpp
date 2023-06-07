// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* a,Node* b)
{
	Node* temp=new Node(0);
    Node* res=temp;

	while(a && b){
		if(a->data<b->data){
			temp->child=a;
			temp=a;
			a=a->child;
		}
		else{
			temp->child=b;
			temp=b;
			b=b->child;
		}
	}
	if(a) temp->child=a;
	else temp->child=b;
	return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head->next) return head;
    Node *right = flattenLinkedList(head->next);
    head->next= NULL;
    Node *ans=merge(head,right);
    return ans;
}
