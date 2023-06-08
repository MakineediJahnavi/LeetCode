class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int neg=0;
        int row=n-1,col=0;
        while(row>=0 && col<m){
            if(grid[row][col]>=0)
                col++;
            else {
                neg+=m-col;
                row--;
            }
        }
        return neg;
    }
};