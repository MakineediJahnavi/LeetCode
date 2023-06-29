class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        int max_area=0;
        for(int i=0; i<=n; i++) {
            while(!s.empty() && (i==n|| heights[s.top()]>=heights[i])) {
                int temp=s.top();
                s.pop();
                int width;
                if(s.empty())
                    width=i;
                else 
                    width=i-s.top()-1;
                max_area=max(max_area,heights[temp]*(width));
            }
            s.push(i);
        }
        return max_area;
    }
};