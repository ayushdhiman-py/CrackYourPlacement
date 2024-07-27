class Solution {
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool solve(int i, int j, vector<vector<char>>& board, int idx, string& w) {
        int n = board.size();
        int m = board[0].size();
        if (idx == w.length())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#' ||
            board[i][j] != w[idx]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';

        for (auto& dir : dirs) {
            int _i = i + dir[0];
            int _j = j + dir[1];

            if (solve(_i, _j, board, idx + 1, w)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && solve(i, j, board, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};