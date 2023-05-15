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
        ListNode *p=head,*q=head,*temp;
        k--;
        while(k--) {
            p=p->next;
        }
        temp = p;
        p=p->next;
        while(p) {
            p=p->next;
            q=q->next;
        }
        swap(temp->val,q->val);
        return head;
    }
};