class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<bool> dp(m+1,false);
        dp[0]=true;
        for(int j=1; j<=m; j++){
            bool flag=true;
            for(int k=1; k<=j; k++){
                if(p[k-1]!='*') {
                    flag=false;
                    break;
                }
            }
            dp[j]=flag;
        }
        for(int i=1; i<=n; i++) {
            vector<bool> cur(m+1,false);
            for(int j=1; j<=m; j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    cur[j]=dp[j-1];
                else if(p[j-1]=='*')
                    cur[j]=cur[j-1]|dp[j];
                else
                    cur[j]=false;
            }
            dp=cur;
        }
        return dp[m];
    }
};