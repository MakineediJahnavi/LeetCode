//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1,0);
        for(int i=wt[0]; i<=W; i++) {
            dp[i]=val[0]*((int)i/wt[0]);
        }
        for(int i=1; i<N; i++) {
            vector<int> cur(W+1,0);
            for(int j=0; j<=W; j++) {
                int notake=dp[j];
                int take=0;
                if(wt[i]<=j)
                    take=val[i]+cur[j-wt[i]];
                cur[j]=max(take,notake);
            }
            dp=cur;
        }
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends