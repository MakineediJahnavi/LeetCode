//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vi(V,0);
        queue<int> q;
        vector<int> BFS;
        q.push(0);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            vi[x]=1; 
            BFS.push_back(x);
            for(int i=0; i<adj[x].size(); i++) {
                if(vi[adj[x][i]]==0) {
                q.push(adj[x][i]);
                vi[adj[x][i]]=1;
                }
            }
        }
        return BFS;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends