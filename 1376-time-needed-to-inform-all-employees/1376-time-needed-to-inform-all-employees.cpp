class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinate(n);
        for(int i=0; i<n; i++) {
            if(i!=headID)
                subordinate[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(headID);
        vector<int> vis(n,0);
        while(!q.empty()) {
            int s=q.size();
                int emp=q.front();
                q.pop();
                for(auto it: subordinate[emp]) {
                    q.push(it);
                    vis[it]=vis[emp]+informTime[emp];
                }
        }
        int time=0;
        for(auto it: vis)
            time=max(time,it);
        return time;
    }
};