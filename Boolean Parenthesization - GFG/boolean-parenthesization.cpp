//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
private:
    int count(int i,int j,int isTrue,string s,vector<vector<vector<int>>> &dp) {
        if(i>j)
            return 0;
        if(i==j) {
            if(isTrue)
                return s[i]=='T';
            return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue];
        long long ans=0;
        for(int k=i+1; k<j; k+=2) {
            long long tl=count(i,k-1,1,s,dp);
            long long tr=count(k+1,j,1,s,dp);
            long long fl=count(i,k-1,0,s,dp);
            long long fr=count(k+1,j,0,s,dp);
            if(s[k]=='&') {
                if(isTrue)
                    ans=(ans+(tl*tr)%mod)%mod;
                else 
                    ans=(ans+(tl*fr)%mod+(fl*tr)%mod+(fl*fr)%mod)%mod;
            }
            else if(s[k]=='|'){
                if(isTrue)
                    ans=(ans+(tl*tr)%mod+(tl*fr)%mod+(fl*tr)%mod)%mod;
                else
                    ans=(ans+(fl*fr)%mod)%mod;
            }
            else{
                if(isTrue)
                    ans=(ans+(tl*fr)%mod+(fl*tr)%mod)%mod;
                else
                    ans=(ans+(tl*tr)%mod+(fl*fr)%mod)%mod;
            }
        }
        return dp[i][j][isTrue]=ans%mod;
    }
public:
    int countWays(int N, string s){
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<n; j++) {
                if(i>j) continue;
                for(int isTrue=0; isTrue<=1; isTrue++) {
                    if(i==j) {
                        if(isTrue)
                            dp[i][j][isTrue]=s[i]=='T';
                        else
                            dp[i][j][isTrue]=s[i]=='F';
                        continue;
                    }
                    long long ans=0;
                    for(int k=i+1; k<j; k+=2) {
                        long long tl=dp[i][k-1][1];
                        long long tr=dp[k+1][j][1];
                        long long fl=dp[i][k-1][0];
                        long long fr=dp[k+1][j][0];
                        if(s[k]=='&') {
                            if(isTrue)
                                ans=(ans+(tl*tr)%mod)%mod;
                            else 
                                ans=(ans+(tl*fr)%mod+(fl*tr)%mod+(fl*fr)%mod)%mod;
                        }
                        else if(s[k]=='|'){
                            if(isTrue)
                                ans=(ans+(tl*tr)%mod+(tl*fr)%mod+(fl*tr)%mod)%mod;
                            else
                                ans=(ans+(fl*fr)%mod)%mod;
                        }
                        else{
                            if(isTrue)
                                ans=(ans+(tl*fr)%mod+(fl*tr)%mod)%mod;
                            else
                            ans=(ans+(tl*tr)%mod+(fl*fr)%mod)%mod;
                        }
                    }
                    dp[i][j][isTrue]=ans%mod;
                }
            }
        }
        return dp[0][n-1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends