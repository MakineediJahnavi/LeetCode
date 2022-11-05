class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i])!=m.end())
                result.push_back(nums[i]);
            m[nums[i]]=i;
        }
        return result;
    }
};