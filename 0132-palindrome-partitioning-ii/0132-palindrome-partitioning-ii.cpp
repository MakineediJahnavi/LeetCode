class Solution {
private:
    bool isPalindrome(int i,int j,string &s) {
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    int cuts(int i,string &s,vector<int> &dp) {
        if(i==s.length() || isPalindrome(i,s.length()-1,s))
            return 0; 
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int ind=i; ind<s.length(); ind++) {
            if(isPalindrome(i,ind,s)) {
                ans=min(ans,1+cuts(ind+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return cuts(0,s,dp);
    }
};