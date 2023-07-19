bool comp(vector<int> &a,vector<int> &b) {
    return (a[1]<b[1]);
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int prev=INT_MIN;
        int count=0;
        for(int i=0; i<intervals.size(); i++) {
            if(intervals[i][0]<prev)
                count++;
            else 
                prev=intervals[i][1];
        }
        return count;
    }
};