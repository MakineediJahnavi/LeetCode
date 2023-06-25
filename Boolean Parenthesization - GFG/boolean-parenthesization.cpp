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
    int countWays(int N, string S){
        int n=S.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return count(0,n-1,1,S,dp);
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