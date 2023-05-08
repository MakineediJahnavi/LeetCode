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
        int n=0,m=0;
        ListNode *p=headA,*q=headB;
        while(p!=NULL) {
            n++;
            p=p->next;
        }
        while(q!=NULL) {
            m++;
            q=q->next;
        }
        if(n>m) {
            int t=n-m;
            while(t--) {
                headA=headA->next;
            }
        }
        else {
           int t=m-n;
            while(t--) {
                headB=headB->next;
            } 
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};