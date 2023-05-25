//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,stack<int> &s) {
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]) {
	            dfs(it,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	void dfs2(int node,vector<int> &vis,vector<vector<int>> &adj) {
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it])
	            dfs2(it,vis,adj);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0; i<V; i++) {
            if(!vis[i])
                dfs(i,vis,adj,s);
        }
        vector<vector<int>> radj(V);
        for(int i=0; i<V; i++) {
            for(auto it:adj[i]) {
                radj[it].push_back(i);
            }
        }
        vector<int> rvis(V,0);
        int count=0;
        while(!s.empty()) {
            int node=s.top();
            s.pop();
            if(!rvis[node]) {
                dfs2(node,rvis,radj);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends