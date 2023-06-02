class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]++;
        int prefix_sum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++) {
            prefix_sum+=nums[i];
            if(m.find(prefix_sum-k)!=m.end())
                count+=m[prefix_sum-k];
            m[prefix_sum]++;
        }
        return count;
    }
};