class Solution {
vector<vector<long long>> comb;
private:
    long long dfs(vector<int> &nums,long long mod) {
        int n=nums.size();
        if(n<=2)
            return 1;
        int root=nums[0];
        vector<int> l,r;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]<root)
                l.push_back(nums[i]);
            else
                r.push_back(nums[i]);
        }
        long long left=dfs(l,mod)%mod;
        long long right=dfs(r,mod)%mod;
        return (((comb[n-1][l.size()]*left)%mod)*right)%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        long long mod = 1e9+7;
        comb.resize(n+1);
        for(int i=0; i<=n; i++) {
            comb[i]=vector<long long> (i+1,1);
            for(int j=1; j<i; j++) {
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
            }
        }
        long long ans=dfs(nums,mod);
        return (ans%mod-1)%mod;
    }
};