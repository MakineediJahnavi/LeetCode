//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int src, int parent, vector<int> &visited, vector<int> adj[]){
        visited[src]=1;
            for(int i=0; i<adj[src].size(); i++) {
                if(visited[adj[src][i]]==0) {
                    if(detect(adj[src][i],src,visited,adj))
                        return true;
                }
                else if(parent!=adj[src][i]){
                    return true;
                }
            }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(detect(i,-1,visited,adj))
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