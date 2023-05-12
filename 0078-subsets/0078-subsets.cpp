class Solution {
private: 
    void subSets(vector<vector<int>> &ans, vector<int> &nums,vector<int> temp, int i, int n) {
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        subSets(ans,nums,temp,i+1,n);
        temp.pop_back();
        subSets(ans,nums,temp,i+1,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subSets(ans,nums,temp,0,nums.size());
        return ans;
    }
};