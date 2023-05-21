class Solution {
    bool isCycle(int i,vector<int> &vis,vector<int> &pVis,vector<vector<int>> &graph,vector<int> &check) {
        vis[i]=1;
        pVis[i]=1;
        for(auto it:graph[i]) {
            if(!vis[it]) {
                if(isCycle(it,vis,pVis,graph,check)) {
                    return true;
                }
            }
            else if(pVis[it]) {
                return true;
            }
        }
        pVis[i]=0;
        check[i]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pVis(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                isCycle(i,vis,pVis,graph,check);
            }
        }
        for(int i=0; i<n; i++) {
            if(check[i])
                ans.push_back(i);
        }
        return ans;
    }
};