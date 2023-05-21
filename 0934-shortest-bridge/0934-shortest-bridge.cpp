class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int dr[],int dc[],queue<pair<int,int>> &q) {
        vis[row][col]=1;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<4; i++) {
            int x=row+dr[i];
            int y=col+dc[i];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1)
                dfs(x,y,vis,grid,dr,dc,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        bool found=false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    dfs(i,j,vis,grid,dr,dc,q);
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        int steps=0;
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0; i<4; i++) {
                    int x=r+dr[i];
                    int y=c+dc[i];
                    if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]) {
                        if(grid[x][y]==1)
                            return steps;
                        q.push({x,y});
                        vis[x][y]=1;
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};