class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int> dp(m+1,0);
        for(int j=0; j<=m; j++)
            dp[j]=j;
        for(int i=1; i<=n; i++) {
            vector<int> cur(m+1,0);
            cur[0]=i;
            for(int j=1; j<=m; j++) {
                if(word1[i-1]==word2[j-1]) {
                    cur[j]=dp[j-1];
                }
                else {
                    int ins=1+cur[j-1];
                    int del=1+dp[j];
                    int rep=1+dp[j-1];
                    int mini=min(ins,del);
                    cur[j]=min(mini,rep);
                }
            }
            dp=cur;
        }
        return dp[m];
    }
};