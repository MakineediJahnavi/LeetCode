class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(auto q: queries) {
            int len=0;
            for(auto it: nums) {
                if(q>=it) {
                    q-=it;
                    len++;
                }
            }
            ans.push_back(len);
        }
        return ans;
    }
};