//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, vector<int> &visited, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src]=1;
        while(!q.empty()) {
            int n=q.size();
           while(n--) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0; i<adj[x].size(); i++) {
                    if(visited[adj[x][i]]==0) {
                        q.push({adj[x][i],x});
                        visited[adj[x][i]]=1;
                    }
                    else if(y!=adj[x][i]){
                        return true;
                    }
                    }
                }
            }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(detect(i,visited,adj))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends