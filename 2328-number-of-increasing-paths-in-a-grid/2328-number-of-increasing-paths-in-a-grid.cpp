class Solution {
    int mod=1e9+7;
private:
    int fun(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp,int dr[],int dc[]){
        int n=grid.size();
        int m=grid[0].size();
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1;
        for(int k=0; k<4; k++) {
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[i][j]<grid[r][c])
                ans=(ans%mod+fun(r,c,grid,dp,dr,dc)%mod)%mod;
        }
        return dp[i][j]=ans%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long count=0;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                count=(count%mod+fun(i,j,grid,dp,dr,dc)%mod)%mod;
            }
        }
        return (int)count%mod;
    }
};