// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=1;
        ListNode* p=head;
        while(p->next){
            n++;
            p=p->next;
        }
        p->next=head;
        k=k%n;
        n=n-k-1;
        ListNode* q=head;
        while(n--) q=q->next;
        head=q->next;
        q->next=NULL;
        return head;
    }
};
