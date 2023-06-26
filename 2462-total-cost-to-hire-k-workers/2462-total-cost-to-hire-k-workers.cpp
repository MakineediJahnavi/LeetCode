class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> lp,rp;
        int l=0,r=costs.size()-1,cnt=0;
        long long cost=0; 
        while(cnt<k) {
            while(lp.size()<candidates && l<=r) {
                lp.push(costs[l++]);
            }
            while(rp.size()<candidates && r>=l) {
                rp.push(costs[r--]);
            }
            int a=lp.size()?lp.top():INT_MAX;
            int b=rp.size()?rp.top():INT_MAX;
            if(a<=b) {
                cost+=a;
                lp.pop();
            }
            else {
                cost+=b;
                rp.pop();
            }
            cnt++;
        }
        return cost;
    }
};