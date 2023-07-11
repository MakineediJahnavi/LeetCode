/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parents) {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *cur=q.front();
            q.pop();
            if(cur->left) {
                parents[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right) {
                parents[cur->right]=cur;
                q.push(cur->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0)
            return {target->val};
        unordered_map<TreeNode*, TreeNode*> parents;
        findParents(root,parents);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dist=0;
        while(!q.empty()) {
            int s=q.size();
            while(s--){
                TreeNode *cur=q.front();
                q.pop();
                if(parents[cur] && !visited[parents[cur]]) {
                    q.push(parents[cur]);
                    visited[parents[cur]]=true;
                }
                if(cur->left && !visited[cur->left]) {
                    q.push(cur->left);
                    visited[cur->left]=true;
                }
                if(cur->right && !visited[cur->right]) {
                    q.push(cur->right);
                    visited[cur->right]=true;
                }
            }
            dist++;
            if(dist==k)
                break;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};