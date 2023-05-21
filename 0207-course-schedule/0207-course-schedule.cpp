class Solution {
private:
    bool isCycle(int i,vector<int> &vis,vector<int> &pVis,vector<vector<int>> &adj) {
        vis[i]=1;
        pVis[i]=1;
        for(auto it:adj[i]) {
            if(!vis[it]) {
                if(isCycle(it,vis,pVis,adj))
                    return true;
            }
            else if(pVis[it])
                return true;
        }
        pVis[i]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pVis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(isCycle(i,vis,pVis,adj))
                    return false;
            }
        }
        return true;
    }
};