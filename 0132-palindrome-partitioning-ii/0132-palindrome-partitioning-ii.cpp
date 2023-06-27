class Solution {
private:
    bool isPalindrome(int i,int j,string &s) {
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++; j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n=s.length();
        if(isPalindrome(0,n-1,s))
            return 0;
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--) {
            int ans=INT_MAX;
            for(int ind=i; ind<n; ind++) {
                if(isPalindrome(i,ind,s)) {
                    ans=min(ans,1+dp[ind+1]);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
};