class Solution {
public:
    vector<string> ans;
    bool isSafe(int x, int y, vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        return (x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '#');
    }
    vector<pair<int, int>> movements = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void func(int x, int y, string &curr, vector<vector<char>> &board, unordered_set<string> &st)
    {
        if (curr.size() >= 10)
            return;
        if (!isSafe(x, y, board))
            return;
        curr += board[x][y];
        if (st.find(curr) != st.end())
        {
            st.erase(curr);
            ans.push_back(curr);
        }
        curr.pop_back();
        char ch = board[x][y];
        for (auto it : movements)
        {
            int nx = x + it.first;
            int ny = y + it.second;
            curr += board[x][y];
            board[x][y] = '#';
            func(nx, ny, curr, board, st);
            curr.pop_back();
            board[x][y] = ch;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st;
        for (auto it : words)
            st.insert(it);
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                string curr = "";
                func(i, j, curr, board, st);
            }
        }
        return ans;
    }
};