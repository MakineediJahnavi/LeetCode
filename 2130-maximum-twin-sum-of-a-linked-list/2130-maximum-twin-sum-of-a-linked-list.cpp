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
    int pairSum(ListNode* head) {
        vector<int> a;
        ListNode *p=head;
        while(p) {
            a.push_back(p->val);
            p=p->next;
        }
        int i=0,j=a.size()-1;
        int sum=INT_MIN;
        while(i<j) {
            sum=max(sum,a[i]+a[j]);
            i++; j--;
        }
        return sum;
    }
};