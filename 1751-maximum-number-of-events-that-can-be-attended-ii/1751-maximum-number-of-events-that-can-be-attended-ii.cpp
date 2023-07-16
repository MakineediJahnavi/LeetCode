class Solution {
private:
    int nextindex(int i,vector<pair<int,pair<int,int>>> &m){
        int end=m[i].second.first;
        int l=i+1,r=m.size();
        while(l<r){
            int mid=(l+r)/2;
            if(m[mid].first>end){
                r=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
    int fun(int i,vector<pair<int,pair<int,int>>> &m,int k,vector<vector<int>> &dp) {
        if(i==m.size())
            return 0;
        if(k==0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int next=nextindex(i,m);
        int notake = fun(i+1,m,k,dp);
        int take=m[i].second.second+fun(next,m,k-1,dp);
        return dp[i][k]=max(take,notake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        vector<pair<int,pair<int,int>>> m;
        for(auto it: events) {
            m.push_back({it[0],{it[1],it[2]}});
        }
        sort(m.begin(),m.end());
        return fun(0,m,k,dp);
    }
};