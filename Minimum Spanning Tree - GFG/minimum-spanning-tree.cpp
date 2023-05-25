//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> size;
    vector<int> parent;
    public:
    DisjointSet(int V) {
        parent.resize(V);
        size.resize(V,0);
        for(int i=0; i<V; i++) {
            parent[i]=i;
        }
    }
        int u_p(int n) {
            if(n==parent[n])
                return n;
            return parent[n]=u_p(parent[n]);
        }
        
        void unionBySize(int u, int v) {
            if(u_p(u)==u_p(v))
                return;
            if(size[u_p(u)]<size[u_p(v)]){
                parent[u_p(u)]=u_p(v);
                size[u_p(v)]+=size[u_p(u)];
            }
            else {
                parent[u_p(v)]=u_p(u);
                size[u_p(u)]+=size[u_p(v)];
            }
        }
};
class Solution
{   
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<V; i++) {
            for(auto it: adj[i]) {
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        int mst=0;
        DisjointSet ds(V);
        for(auto it:edges) {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            if(ds.u_p(u)!=ds.u_p(v)) {
                mst+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mst;
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