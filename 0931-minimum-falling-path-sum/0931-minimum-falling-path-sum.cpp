class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,0);
        for(int i=0; i<n; i++) {
            dp[i]=matrix[0][i];
        }
        for(int i=1; i<n; i++) {
            vector<int> temp(n,0);
            for(int j=0; j<n; j++) {
                int l=INT_MAX;
                if(j>0) 
                    l=matrix[i][j]+dp[j-1];
                int m=matrix[i][j]+dp[j];
                int r=INT_MAX;
                if(j<n-1)
                    r=matrix[i][j]+dp[j+1];
                temp[j]=min(l,m);
                temp[j]=min(temp[j],r);
            }
            dp=temp;
        }
        int min_path=dp[0];
        for(auto it:dp)
            min_path=min(min_path,it);
        return min_path;
    }
};