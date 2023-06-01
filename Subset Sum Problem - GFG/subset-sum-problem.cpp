//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
private:
    bool func(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {
        if(target==0)
            return true;
        if(ind==0)
            return arr[ind]==target;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        bool noTake=func(ind-1,target,arr,dp);
        bool take = false;
        if(target>=arr[ind])
            take=func(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=take||noTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return func(arr.size()-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends