// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        if(!head->next->next) return (head->val==head->next->val);
        
        ListNode* p=head;
        ListNode* q=head;
        ListNode* r;
        
        while(p->next && p->next->next){
            p=p->next->next;
            q=q->next;
        }
        r=q;
        q=q->next;
        r->next=NULL;
        
        ListNode* a=head;
        ListNode* b=NULL;
        ListNode* c=NULL;
        
        while(a){
            c=b;
            b=a;
            a=a->next;
            b->next=c;
        }
        
        if(!p->next) r=r->next;
        
        while(r && q){
            if(r->val==q->val){
                r=r->next;
                q=q->next;
            }
            else return 0;
        }
        return 1;
    }
};
