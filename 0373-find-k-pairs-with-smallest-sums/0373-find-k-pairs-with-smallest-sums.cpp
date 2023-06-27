class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>> q;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                int sum=nums1[i]+nums2[j];
                if(q.size()<k)
                    q.push({sum,{nums1[i],nums2[j]}});
                else if(sum<q.top().first) {
                    q.pop();
                    q.push({sum,{nums1[i],nums2[j]}});
                }
                else
                    break;
            }
        }
        while(q.size()>0) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};