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
        stack<int> x,y;
        while(l1!=NULL) {
            x.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL) {
            y.push(l2->val);
            l2=l2->next;
        }
        ListNode *head=NULL;
        int c=0;
        while(!x.empty() && !y.empty()){
            ListNode *temp=new ListNode((x.top()+y.top()+c)%10);
            c=(x.top()+y.top()+c)/10;
            x.pop(); y.pop();
            temp->next=head;
            head=temp;
        }
        while(!y.empty()){
            ListNode *temp=new ListNode((y.top()+c)%10);
            c=(y.top()+c)/10;
            y.pop();
            temp->next=head;
            head=temp;
        }
        while(!x.empty()){
            ListNode *temp=new ListNode((x.top()+c)%10);
            c=(x.top()+c)/10;
            x.pop();
            temp->next=head;
            head=temp;
        }
        if(c!=0) {
            ListNode *temp=new ListNode(c);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};