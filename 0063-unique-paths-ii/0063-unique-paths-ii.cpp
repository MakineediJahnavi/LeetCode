class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=0; i<m; i++) {
            vector<int> temp(n,0);
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j]==1)
                    continue;
                temp[j]+=dp[j];
                if(j>0)
                    temp[j]+=temp[j-1];
            }
            dp=temp;
        }
        return dp[n-1];
    }
};