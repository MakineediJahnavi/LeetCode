class Solution {
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,int dr[],int dc[]) {
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<4; i++) {
            int x=row+dr[i];
            int y=col+dc[i];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && board[x][y]=='O')
                dfs(x,y,vis,board,dr,dc);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0; j<m; j++) {
            if(!vis[0][j] && board[0][j]=='O')
                dfs(0,j,vis,board,dr,dc);
            if(!vis[n-1][j] && board[n-1][j]=='O')
                dfs(n-1,j,vis,board,dr,dc);
        }
        for(int i=0; i<n; i++) {
            if(!vis[i][0] && board[i][0]=='O')
                dfs(i,0,vis,board,dr,dc);
            if(!vis[i][m-1] && board[i][m-1]=='O')
                dfs(i,m-1,vis,board,dr,dc);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
};