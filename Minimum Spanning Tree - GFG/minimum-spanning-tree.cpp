//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    typedef pair<int,pair<int,int>> p;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V,0);
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,-1}});
        int weight=0;
        while(!pq.empty()) {
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            int wt=pq.top().first;
            pq.pop();
            if(!vis[u]) {
                vis[u]=1;
                weight+=wt;
                for(auto it:adj[u]) {
                    pq.push({it[1],{it[0],u}});
                }
            }
        }
        return weight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends