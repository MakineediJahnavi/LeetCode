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
        while(l1!=NULL || l2!=NULL || c) {
            p->next=new ListNode();
            p=p->next;
            int sum=0;
            if(l1) {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2) {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=c;
            p->val=sum%10;
            c=sum/10;
        }
        return q->next;
    }
};