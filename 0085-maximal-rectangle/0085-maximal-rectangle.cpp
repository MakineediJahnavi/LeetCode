class Solution {
private:
    int area(vector<int> &heights) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int max_area=0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            max_area=max(max_area,area(heights));
        }
        return max_area;
    }
};