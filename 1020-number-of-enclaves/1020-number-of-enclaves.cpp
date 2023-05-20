class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1) {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int j=0; j<m; j++) {
            if(grid[0][j]==1) {
                q.push({0,j});
                vis[0][j]=1;
            }
            if(grid[n-1][j]==1) {
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int x=r+dr[i];
                int y=c+dc[i];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1) {
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};