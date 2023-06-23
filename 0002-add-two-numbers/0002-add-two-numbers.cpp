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
        ListNode *p=new ListNode();
        ListNode *q=p;
        int c=0;
        while(l1!=NULL && l2!=NULL) {
            p->next=new ListNode();
            p=p->next;
            p->val=(l1->val+l2->val+c)%10;
            c=(l1->val+l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL) {
            p->next=new ListNode();
            p=p->next;
            p->val=(l1->val+c)%10;
            c=(l1->val+c)/10;
            l1=l1->next;
        }
        while(l2!=NULL) {
            p->next=new ListNode();
            p=p->next;
            p->val=(l2->val+c)%10;
            c=(l2->val+c)/10;
            l2=l2->next;
        }
        if(c){
            p->next=new ListNode();
            p=p->next;
            p->val=c;}
        return q->next;
    }
};