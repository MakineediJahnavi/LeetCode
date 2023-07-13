class Solution {
private:
    bool isCycle(int i,vector<int> &vis,vector<int> &pvis,vector<vector<int>> &adj) {
        vis[i]=1;
        pvis[i]=1;
        for(auto it: adj[i]) {
            if(!vis[it]){
                if(isCycle(it,vis,pvis,adj))
                    return true;
            }
            if(pvis[it])
                return true;
        }
        pvis[i]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pvis(numCourses,0);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]){
                if(isCycle(i,vis,pvis,adj))
                    return false;
            }
        }
        return true;
    }
};