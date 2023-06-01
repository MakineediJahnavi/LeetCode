class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        if(n==1 && grid[0][0]==0)
            return 1;
        vector<vector<int>> visited=grid;
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;
        int dr[] = {-1,-1,-1,0,+1,+1,+1,0};
        int dc[] = {-1,0,+1,+1,+1,0,-1,-1};
        int steps=1;
        while(!q.empty()) {
            int s=q.size();
            while(s--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                visited[r][c]=1;
                for(int i=0; i<8; i++) {
                    int x=r+dr[i];
                    int y=c+dc[i];
                    if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==0){
                        if(x==n-1 && y==n-1)
                            return steps+1;
                        else {
                            visited[x][y]=1;
                            q.push({x,y});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};