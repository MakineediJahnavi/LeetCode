//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int fun(int i,int j,int arr[],vector<vector<int>> &dp) {
        if(i==j)
            return dp[i][j]=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int steps=1e9;
        for(int k=i; k<=j-1; k++) {
            int ans=arr[i-1]*arr[k]*arr[j]+fun(i,k,arr,dp)+fun(k+1,j,arr,dp);
            steps=min(steps,ans);
        }
        return dp[i][j]=steps;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        fun(1,N-1,arr,dp);
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends