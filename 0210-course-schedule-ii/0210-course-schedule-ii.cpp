class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indg(numCourses,0);
        vector<int> adj[numCourses];
        vector<int> ans;
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++) {
            for(auto it:adj[i]) {
                indg[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<indg.size(); i++) {
            if(indg[i]==0)
                q.push(i);
        }
        while(!q.empty()) {
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for(auto it:adj[x]){
                indg[it]--;
                if(indg[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};