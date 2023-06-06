// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0,n2=0;
        ListNode* p=l1;
        ListNode* q=l2;
        while(p){
            p=p->next;
            n1++;
        }
        while(q){
            q=q->next;
            n2++;
        }
        if(n1>n2) { p=l1;q=l2; } 
        else { p=l2;q=l1; }
        ListNode* r=NULL;
        int c=0;
        while(p && q){
            int sum=p->val+q->val+c;
            if(sum>9) c=1;
            else c=0;
            p->val=sum%10;
            r=p;
            p=p->next;
            q=q->next;
        }
        while(p){
            int sum=p->val+c;
            if(sum>9) c=1;
            else c=0;
            p->val=sum%10;
            r=p;
            p=p->next;
        }
        if(c){
            ListNode* d=new ListNode(1);
            r->next=d;
        }
        return (n1>n2) ? l1 : l2;
    }
};
