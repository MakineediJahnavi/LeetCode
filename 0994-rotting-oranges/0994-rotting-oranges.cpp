class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int r[] = {-1,0,+1,0};
        int c[] = {0,+1,0,-1};
        int cntFresh=0;
        int tm=0,cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1)
                    cntFresh++;
                else if(grid[i][j]==2) {
                    vis[i][j]=1;
                    q.push({i,j}); }
            }
        }
                    while(!q.empty()) {
                        int qs=q.size();
                        for(int p=0; p<qs; p++){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0; k<4; k++) {
                            int dr=x+r[k];
                            int dc=y+c[k];
                            if(dr>=0 && dr<n && dc>=0 && dc<m && vis[dr][dc]==0 && grid[dr][dc]==1) {
                                vis[dr][dc]=1;
                                q.push({dr,dc});
                                cnt++;
                            }
                        }
                    }
                    if(!q.empty())
                    tm++;
                    } 
        if(cnt!=cntFresh)
            return -1;
        return tm;

    }
};