//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool> dp(sum+1,0);
        dp[arr[0]]=true;
        dp[0]=true;
        for(int i=1; i<n; i++) {
            vector<bool> temp(sum+1,0);
            temp[0]=true;
            for(int j=1; j<=sum; j++) {
                bool noTake=dp[j];
                bool take = false;
                if(j>=arr[i])
                    take=dp[j-arr[i]];
                temp[j]=take|noTake;
            }
            dp=temp;
        }
        return dp[sum];
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