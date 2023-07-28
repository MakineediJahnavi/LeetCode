class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1; i>=0; i--) {
            int ans=false;
            for(int j=0; j<wordDict.size(); j++) {
                if(i+wordDict[j].length()<=n){
                    string temp=s.substr(i,wordDict[j].length());
                    if(temp==wordDict[j])
                        ans |=dp[i+wordDict[j].length()];
                }
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};