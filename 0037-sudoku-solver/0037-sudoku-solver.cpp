class Solution {
public:
    bool isvalid(int i,int j,char k,vector<vector<char>> &board) {
        for(int x=0; x<9; x++) {
            if(board[x][j]==k)
                return false;
            if(board[i][x]==k)
                return false;
            if(board[3*(i/3)+x/3][3*(j/3)+x%3]==k)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]=='.') {
                    for(char k='1'; k<='9'; k++) {
                        if(isvalid(i,j,k,board)) {
                            board[i][j] = k;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};