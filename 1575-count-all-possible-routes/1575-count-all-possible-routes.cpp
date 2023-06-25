class Solution {
    int mod=1e9+7;
private:
    int count(int i,int j,int fuel,vector<int> &locations,vector<vector<int>> &dp) {
        if(fuel<0)
            return 0;
        if(dp[i][fuel]!=-1)
            return dp[i][fuel];
        int ans=0;
        if(i==j)
            ans++;
        for(int k=0; k<locations.size(); k++) {
            if(k!=i) {
                int f=abs(locations[i]-locations[k]);
                if(f<=fuel){
                    ans=(ans+count(k,j,fuel-f,locations,dp))%mod;
                }
            }
        }
        return dp[i][fuel]=ans%mod;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,-1));
        return count(start,finish,fuel,locations,dp);
    }
};