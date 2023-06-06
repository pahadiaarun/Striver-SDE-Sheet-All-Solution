// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* d=new ListNode;
        d->next=head;
        ListNode* f=d;
        ListNode* s=d;
        while(n--) f=f->next;
        while(f->next){
            f=f->next;
            s=s->next;
        }
        if(s==d) return head->next;
        s->next=s->next->next;
        delete(d);
        return head;
    }
};
