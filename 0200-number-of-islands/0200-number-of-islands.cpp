class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int x, int y) {
        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1' && vis[x][y]==0){
        vis[x][y]=1;
        bfs(grid,vis,x-1,y);
        bfs(grid,vis,x,y+1);
        bfs(grid,vis,x+1,y);
        bfs(grid,vis,x,y-1);}
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int islands=0;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0 && grid[i][j]=='1') {
                    bfs(grid, vis, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};