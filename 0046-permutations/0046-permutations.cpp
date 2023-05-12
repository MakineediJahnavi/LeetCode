class Solution {
private:
    void permutations(vector<int> nums,vector<vector<int>> &ans,vector<int> temp,vector<int> freq) {
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return ;
        }
        for(int i=0; i<nums.size(); i++) {
            if(freq[i]==0) {
                freq[i]=1;
                temp.push_back(nums[i]);
                permutations(nums,ans,temp,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> freq(nums.size(),0);
        permutations(nums,ans,temp,freq);
        return ans;
    }
};