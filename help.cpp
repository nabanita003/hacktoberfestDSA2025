class Solution {
public:
    bool help(vector<vector<char>>& board, string word, int i, int j, int k) {
        int m = board.size(), n = board[0].size();
        if (k >= word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') return false;
        if (word.size() == 1 && word[k] == board[i][j]) return true;
        if (word[k] != board[i][j]) return false;
        board[i][j] = '$';
        bool temp = false;
        int x[4] = {0, 0, -1, 1};
        int y[4] = {-1, 1, 0, 0};

        for (int idx = 0; idx < 4; idx++) {
            temp = temp || help(board, word, i + x[idx], j + y[idx], k + 1);
        }
        board[i][j] = word[k];
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (word.size() == 0) return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    if (help(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
