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
private:
    void inorder(TreeNode *root,vector<int> &inord) {
        if(root==NULL)
            return;
        inorder(root->left,inord);
        inord.push_back(root->val);
        inorder(root->right,inord);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inord;
        inorder(root,inord);
        int ans=INT_MAX;
        for(int i=1; i<inord.size(); i++) {
            ans=min(ans,inord[i]-inord[i-1]);
        }
        return ans;
    }
};