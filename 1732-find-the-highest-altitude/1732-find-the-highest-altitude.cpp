class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int prev=0,cur=0;
        int highalt=0;
        for(int i=0; i<n; i++) {
            cur=prev+gain[i];
            prev=cur;
            highalt=max(highalt,cur);
        }
        return highalt;
    }
};