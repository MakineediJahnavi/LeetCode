class Solution {
private:
    int fun(int i,vector<int> &arr,int k,vector<int> &dp) {
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MIN;
        int maxi=0,l=0;
        for(int ind=i; ind<i+k; ind++) {
            if(ind>=arr.size())
                break;
            l++;
            maxi=max(maxi,arr[ind]);
            ans=max(ans,maxi*l+fun(ind+1,arr,k,dp));
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return fun(0,arr,k,dp);
    }
};