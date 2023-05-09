class Solution {
public:
    void dfs(vector<vector<int>> &image,vector<vector<int>> &mi,int sr,int sc,int dr[],int dc[],int color,int ini) {
        mi[sr][sc] = color;
        for(int i=0; i<4; i++) {
            int x=sr+dr[i];
            int y=sc+dc[i];
            if(x>=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==ini && mi[x][y]!=color)
                dfs(image,mi,x,y,dr,dc,color,ini);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> mi = image;
        int ini = image[sr][sc];
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        dfs(image,mi,sr,sc,dr,dc,color,ini);
        return mi;
    }
};