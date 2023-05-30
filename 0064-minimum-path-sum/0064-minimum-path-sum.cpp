class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,0);
        for(int i=0; i<m; i++) {
            vector<int> temp(n,0);
            for(int j=0; j<n; j++) {
                int top=INT_MAX;
                if(i==0&&j==0)
                    top=grid[0][0];
                else if(i>0)
                    top=grid[i][j]+dp[j];
                int left=INT_MAX;
                if(j>0)
                    left=grid[i][j]+temp[j-1];
                temp[j]=min(top,left);
            }
            dp=temp;
        }
        return dp[n-1];
    }
};