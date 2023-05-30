class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<int> dp(m,0);
        for(int i=0; i<n; i++) {
            vector<int> temp(m,0);
            for(int j=0; j<=i; j++) {
                int top=INT_MAX;
                if(i==0&&j==0)
                    top=triangle[0][0];
                else if(i>0 && j!=i)
                    top=triangle[i][j]+dp[j];
                int right=INT_MAX;
                if(j>0)
                    right=triangle[i][j]+dp[j-1];
                temp[j]=min(top,right);
            }
            dp=temp;
        }
        int min_path=dp[0];
        for(int i=1; i<m; i++)
            min_path=min(min_path,dp[i]);
        return min_path;
    }
};