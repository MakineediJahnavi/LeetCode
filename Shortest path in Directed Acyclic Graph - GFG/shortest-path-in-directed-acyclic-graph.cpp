//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void dfs(int i,vector<int> &vis,vector<pair<int,int>> adj[],stack<int> &s) {
         vis[i]=1;
         for(auto it:adj[i]) {
             if(!vis[it.first])
                dfs(it.first,vis,adj,s);
         }
         s.push(i);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> vis(N,0);
        stack<int> s;
        for(int i=0; i<N; i++) {
            if(!vis[i]) 
                dfs(i,vis,adj,s);
        }
        vector<int> dist(N);
        for(int i=0; i<N; i++) {
            dist[i]=1e9;
        }
        dist[0]=0;
        while(!s.empty()) {
            int x=s.top();
            s.pop();
            for(auto it:adj[x]) {
                dist[it.first]=min(dist[it.first],it.second+dist[x]);
            }
        }
        for(int i=0; i<N; i++) {
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends