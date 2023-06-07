// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int ctr=0;
        ListNode* p=head;
        while(p){
            ctr++;
            p=p->next;
        }
        ListNode* d=new ListNode(0);
        d->next=head;
        p=d;
        ListNode* q;
        ListNode* r;
        while(ctr>=k){
            q=p->next;
            r=q->next;
            for(int i=1;i<k;i++){
                q->next=r->next;
                r->next=p->next;
                p->next=r;
                r=q->next;
            }
            p=q;
            ctr-=k;
        }
        return d->next;
    }
};

