class Solution {
private:
    int subSeq(int i,int j,string s,string t,vector<vector<int>> &dp) {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=subSeq(i-1,j-1,s,t,dp)+subSeq(i-1,j,s,t,dp);
        else
            return dp[i][j]=subSeq(i-1,j,s,t,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return subSeq(n-1,m-1,s,t,dp);
    }
};