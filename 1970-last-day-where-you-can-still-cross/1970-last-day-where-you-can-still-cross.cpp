class Solution {
public:
    int dr[4]={-1,0,+1,0};
    int dc[4]={0,+1,0,-1};
    bool isPossible(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &visited) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(i==n-1)
            return true;
        visited[i][j]=1;
        bool ans=false;
        for(int k=0; k<4; k++) {
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && !matrix[r][c]) {
                ans |=isPossible(r,c,matrix,visited);
            }
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int days=0;
        int i=0,j=cells.size()-1;
        while(i<=j) {
            int mid=(i+j)/2;
            vector<vector<int>> matrix(row,vector<int>(col,0));
            for(int i=0; i<=mid; i++) {
                int r=cells[i][0];
                int c=cells[i][1];
                matrix[r-1][c-1]=1;
            }
            bool ans=false;
            vector<vector<int>> visited=matrix;
            for(int k=0; k<col; k++) {
                if(!matrix[0][k] && !visited[0][k])
                    ans |=isPossible(0,k,matrix,visited);
            }
            if(ans) {
                days=mid;
                i=mid+1;
            }
            else 
                j=mid-1;
        }
        return ++days;
    }
};