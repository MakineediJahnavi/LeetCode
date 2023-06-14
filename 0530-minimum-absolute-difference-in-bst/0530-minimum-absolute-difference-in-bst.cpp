/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *pre=NULL;
        TreeNode *cur=root;
        int ans=INT_MAX;
        while(cur!=NULL||!s.empty()){
            while(cur!=NULL){
            s.push(cur);
            cur=cur->left;
            }
            TreeNode *t=s.top();
            s.pop();
            if(pre!=NULL)
                ans=min(ans,t->val-pre->val);
            pre=t;
            cur=t->right;
        }
        return ans;
    }
};
