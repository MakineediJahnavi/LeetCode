class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &vis, int x) {
        vis[x]=1;
        for(int i=0; i<graph.size(); i++) {
            if(graph[x][i]==1 && vis[i]==0)
                dfs(graph,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int provinces=0;
            for(int i=0; i<isConnected.size(); i++) {
                if(visited[i]==0){
                    dfs(isConnected,visited,i);
                    provinces++;
                }
            }
        return provinces;
    }
};