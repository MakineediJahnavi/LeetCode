class Solution {
private:
    int len(vector<int> &nums,int num){
        int i;
        for(i=0; i<nums.size(); i++) {
            if(nums[i]==num)
                break;
        }
        int j;
        for(j=nums.size()-1; j>=0; j--) {
            if(nums[j]==num)
                break;
        }
        return j-i+1;
    }
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> m;
        int max_freq=0;
        for(auto it: nums) {
            m[it]++;
            max_freq=max(max_freq,m[it]);
        }
        int ans=INT_MAX;
        for(auto it: m){
            if(it.second==max_freq) {
                ans=min(ans,len(nums,it.first));
            }
        }
        return ans;
    }
};