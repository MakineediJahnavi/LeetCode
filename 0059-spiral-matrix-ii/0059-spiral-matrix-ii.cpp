class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n,vector<int>(n));
        int top=0, bottom=n-1;
        int left=0, right=n-1;
        int x=1;
        while(top<=bottom && left<=right) {
            for(int i=left; i<=right; i++) {
                m[top][i]=x;
                x++;
            }
            top++;
            for(int i=top; i<=bottom; i++) {
                m[i][right]=x;
                x++;
            }
            right--;
            for(int i=right; i>=left; i--) {
                m[bottom][i]=x;
                x++;
            }
            bottom--;
            for(int i=bottom; i>=top; i--) {
                m[i][left]=x;
                x++;
            }
            left++;
        }
        return m;
    }
};