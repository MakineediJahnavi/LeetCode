class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> nums;
        for(int i=0; i<nums1.size(); i++) {
            nums.push_back({nums2[i],nums1[i]});
        }
        sort(nums.rbegin(),nums.rend());
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<k; i++) {
            sum+=nums[i].second;
            pq.push(nums[i].second);
        }
        long long ans=sum*nums[k-1].first;
        for(int i=k; i<nums.size(); i++) {
            sum-=pq.top();
            pq.pop();
            sum+=nums[i].second;
            pq.push(nums[i].second);
            ans=max(ans,sum*nums[i].first);
        }
        return ans;
    }
};