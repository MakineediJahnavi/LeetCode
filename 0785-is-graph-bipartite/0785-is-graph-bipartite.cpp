class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(visited[i]!=0)
                continue;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()) {
                int size=q.size();
                int x=q.front();
                q.pop();
                for (auto it:graph[x]) {
                    if(visited[it]==0) {
                        visited[it]=-visited[x];
                        q.push(it);
                    }
                    else if(visited[it]==visited[x])
                        return false;
                }
            }
        }
        return true;
    }
};