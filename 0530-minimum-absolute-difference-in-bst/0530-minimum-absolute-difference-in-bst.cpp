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
    int num=-1;
    int ans=INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        if(root->left)
            getMinimumDifference(root->left);
        if(num>=0)
            ans=min(ans,abs(root->val-num));
        num=root->val;
        if(root->right)
            getMinimumDifference(root->right);
        return ans;
    }
};
