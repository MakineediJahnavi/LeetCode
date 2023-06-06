class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int l=n+m-dp[n][m]-1;
        string s="";
        for(int i=0; i<=l; i++)
            s+='$';
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]) {
                s[l]=str1[i-1];
                l--; i--; j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                s[l]=str2[j-1];
                l--; j--;
            }
            else {
                s[l]=str1[i-1];
                l--; i--;
            }
        }
        if(i==0) {
            for(int k=j-1; k>=0; k--){
                s[l]=str2[k];
                l--;
            }
        }
        else {
            for(int k=i-1; k>=0; k--){
                s[l]=str1[k];
                l--;
            }
        }
        return s;
    }
};