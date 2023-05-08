//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(int x, vector<int> adj[], vector<int> &vi, vector<int> &ans) {
            vi[x]=1;
            ans.push_back(x);
            for(int i=0; i<adj[x].size(); i++) {
                if(vi[adj[x][i]]==0) {
                    DFS(adj[x][i],adj,vi,ans);
                }
            }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vi(V,0);
        vector<int> ans;
        DFS(0,adj,vi,ans);
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends