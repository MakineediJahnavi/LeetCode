class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n,0);
        dist[start]=1;
        priority_queue<pair<double,int>> q;
        q.push({1,start});
        while(!q.empty()) {
            int cur=q.top().second;
            double curd=q.top().first;
            q.pop();
            for(auto it:graph[cur]){
                if(dist[it.first]<it.second*curd){
                    dist[it.first]=it.second*curd;
                    q.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end];
    }
};