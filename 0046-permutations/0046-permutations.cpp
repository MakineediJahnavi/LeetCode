class Solution {
private:
    void permutations(vector<int> nums,vector<vector<int>> &ans,int ind) {
        if(ind==nums.size()) {
            ans.push_back(nums);
            return ;
        }
        for(int i=ind; i<nums.size(); i++) {
            swap(nums[i],nums[ind]);
            permutations(nums,ans,ind+1);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums,ans,0);
        return ans;
    }
};