class Solution {
private:
    void dfs(int i,vector<int> &visited,vector<vector<int>> &range,int &count) {
        visited[i]=1;
        count++;
        for(auto it:range[i]){
            if(!visited[it]) {
                dfs(it,visited,range,count);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> range(n);
        for(int i=0; i<n; i++) {
            int x=bombs[i][0];
            int y=bombs[i][1];
            long long r=bombs[i][2];
            for(int j=0; j<n; j++) {
                if(i!=j){
                    int x1=bombs[j][0];
                    int y1=bombs[j][1];
                    long long x2=abs(x-x1);
                    long long y2=abs(y-y1);
                    if(x2*x2+y2*y2<=r*r)
                        range[i].push_back(j);
                }
            }
        }
        int max_bombs=INT_MIN;
        for(int i=0; i<n; i++) {
            vector<int> visited(n,0);
            int count=0;
            if(!visited[i])
                dfs(i,visited,range,count);
            max_bombs=max(max_bombs,count);
        }
        return max_bombs;
    }
};