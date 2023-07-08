class Solution {
private: 
    int maxlen(vector<int> prefix_sum,int q) {
        int l=0,r=prefix_sum.size()-1;
        int len=0;
        while(l<=r) {
            int mid=(l+r)/2;
            if(q==prefix_sum[mid]){
                len=mid+1;
                break;
            }
            else if(prefix_sum[mid]<q){
                len=mid+1;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return len;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int> prefix_sum;
        int s=0;
        for(auto it: nums) {
            s+=it;
            prefix_sum.push_back(s);
        }
        for(auto q: queries){
            ans.push_back(maxlen(prefix_sum,q));
        }
        return ans;
    }
};