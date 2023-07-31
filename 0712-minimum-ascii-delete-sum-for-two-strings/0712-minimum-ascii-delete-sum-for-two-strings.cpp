class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=n1-1; i>=0; i--) {
            dp[i][n2]=dp[i+1][n2]+s1[i];
        }
        for(int i=n2-1; i>=0; i--) {
            dp[n1][i]=dp[n1][i+1]+s2[i];
        }
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                int ans;
                if(s1[i]==s2[j])
                    ans=dp[i+1][j+1];
                else
                    ans=min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1]);
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
};