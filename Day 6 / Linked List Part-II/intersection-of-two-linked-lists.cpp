// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p=headA;
        ListNode *q=headB;
        while(p && q){
            if(p==q) break;
            p=p->next;
            q=q->next;
            if(!p && !q) return NULL;
            if(!p) p=headB;
            if(!q) q=headA;
        }
        return p;
    }
};
