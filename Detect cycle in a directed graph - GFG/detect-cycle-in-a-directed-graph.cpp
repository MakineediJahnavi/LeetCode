//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int i,vector<int> &vis,vector<int> &pVis,vector<int> adj[]) {
        vis[i]=1;
        pVis[i]=1;
        for(auto it:adj[i]) {
            if(!vis[it]){
                if(dfs(it,vis,pVis,adj))
                    return true;
            }
            else if(pVis[it])
                return true;
        }
        pVis[i]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pVis(V,0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i,vis,pVis,adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends