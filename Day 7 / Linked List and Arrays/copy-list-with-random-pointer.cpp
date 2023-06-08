// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* p=head;
        while(p){
            Node* n=new Node(p->val);
            n->next=p->next;
            p->next=n;
            p=p->next->next;
        }
        
        p=head;
        while(p){
            Node* q=p->next;
            if(!p->random) q->random=NULL;
            else q->random=p->random->next;
            p=p->next->next;
        }
        
        p=head;
        Node* d=new Node(0);
        d->next=p->next;
        
        while(p){
            Node* q=p->next;
            p->next=q->next;
            if(!p->next) q->next=NULL;
            else q->next=p->next->next;
            p=p->next;
        }
        
        return d->next;
    }
};

