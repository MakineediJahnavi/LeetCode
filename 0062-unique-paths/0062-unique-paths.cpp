class Solution {
    int ways(int i,int j,vector<vector<int>> &dp) {
        if(i==0 && j==0) {
            return dp[i][j]=1;
        }
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=0)
            return dp[i][j];
        return dp[i][j] = ways(i-1,j,dp) + ways(i,j-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        ways(m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};