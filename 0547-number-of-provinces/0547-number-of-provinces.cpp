class Solution {
private:
    void dfs(int node,vector<int> &vis,vector<vector<int>> &isConnected){
        vis[node]=1;
        int n=isConnected.size();
        for(int i=0; i<n; i++){
            if(!vis[i] && isConnected[node][i])
                dfs(i,vis,isConnected);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0; i<n; i++) {
            if(!vis[i]){
                dfs(i,vis,isConnected);
                count++;
            }
        }
        return count;
    }
};