// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *f=head;
        ListNode *s=head;
        do{
            if(!f || !f->next) return NULL;
            f=f->next->next;
            s=s->next;
        }while(f!=s);
        f=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return f;
    }
};
