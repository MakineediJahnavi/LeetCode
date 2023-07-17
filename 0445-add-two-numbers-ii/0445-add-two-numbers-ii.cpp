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
        int x=0,y=0;
        ListNode *q=NULL,*p=l1;
        while(p!=NULL) {
            ListNode *temp=p->next;
            p->next=q;
            q=p;
            p=temp;
        }
        l1=q;
        q=NULL; p=l2;
        while(p!=NULL) {
            ListNode *temp=p->next;
            p->next=q;
            q=p;
            p=temp;
        }
        l2=q;
        ListNode *head=NULL;
        int c=0;
        while(l1!=NULL && l2!=NULL) {
            ListNode *temp=new ListNode((l1->val+l2->val+c)%10);
            c=(l1->val+l2->val+c)/10;
            l1=l1->next;
            l2=l2->next;
            temp->next=head;
            head=temp;
        }
        while(l1!=NULL) {
            ListNode *temp=new ListNode((l1->val+c)%10);
            c=(l1->val+c)/10;
            l1=l1->next;
            temp->next=head;
            head=temp;
        }
        while(l2!=NULL) {
            ListNode *temp=new ListNode((l2->val+c)%10);
            c=(l2->val+c)/10;
            l2=l2->next;
            temp->next=head;
            head=temp;
        }
        if(c) {
            ListNode *temp=new ListNode(c);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};