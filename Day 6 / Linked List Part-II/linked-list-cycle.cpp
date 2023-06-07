// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        ListNode *f=head;
        ListNode *s=head;
        do{
            if(!f || !f->next) return 0;
            f=f->next->next;
            s=s->next;
        }while(f!=s);
        f=head;
        while(f!=s){
            f=f->next;
            s=s->next;
        }
        return 1;
    }
};

