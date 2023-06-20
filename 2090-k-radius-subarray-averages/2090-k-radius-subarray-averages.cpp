class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        vector<long long> presum(n+1);
        presum[0]=0;
        for(int i=1; i<=n; i++) {
            presum[i]=presum[i-1]+nums[i-1];
        }
        for(int i=0; i<n; i++) {
            int l=i-k,r=i+k;
            if(l<0 || r>=n)
                ans.push_back(-1);
            else {
                long long sum=(presum[i+k+1]-presum[i-k]);
                int avg=sum/(2*k+1);
                ans.push_back(avg);
            }
        }
        return ans;
    }
};