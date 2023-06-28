class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> l(n);
        vector<int> r(n);
        stack<int> s;
        for (int i=0; i<n; i++) {
            while(!s.empty() && heights[s.top()]>=heights[i]) {
                s.pop();
            }
            if(s.empty())
                l[i]=0;
            else
                l[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for (int i=n-1; i>=0; i--) {
            while(!s.empty() && heights[s.top()]>=heights[i]) {
                s.pop();
            }
            if(s.empty())
                r[i]=n-1;
            else
                r[i]=s.top()-1;
            s.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            ans=max(ans,heights[i]*(r[i]-l[i]+1));
        }
        return ans;
    }
};