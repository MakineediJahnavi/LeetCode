class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t="";
        for(int i=n-1; i>=0; i--) {
            t+=s[i];
        }
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++) {
            vector<int> temp(n+1,0);
            for(int j=1; j<=n; j++) {
                if(s[i-1]==t[j-1]){
                    temp[j]=1+dp[j-1];
                }
                else{
                    temp[j]=max(dp[j],temp[j-1]);
                }
            }
            dp=temp;
        }
        return dp[n];
    }
};