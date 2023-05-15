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
    int length(ListNode *head) {
        ListNode *p=head;
        int n=0;
        while(p!=NULL) {
            p=p->next;
            n++;
        }
        return n;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p,*q;
        p=head; q=head;
        for(int i=1; i<k; i++) {
            if(p)
                p=p->next;
        }
        int n=length(head);
        for(int i=1; i<=n-k; i++) {
            if(q)
                q=q->next;
        }
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
        return head;
    }
};