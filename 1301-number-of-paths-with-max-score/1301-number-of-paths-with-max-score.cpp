class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));

        dp_score[n - 1][n - 1] = 0;
        dp_paths[n - 1][n - 1] = 1;

        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || dp_score[r][c] == -1) continue;

                int current_score = dp_score[r][c];
                int current_paths = dp_paths[r][c];

                vector<pair<int, int>> next_moves = {{r - 1, c}, {r, c - 1}, {r - 1, c - 1}};

                for (auto& move : next_moves) {
                    int nr = move.first;
                    int nc = move.second;

                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int edge_val = (board[nr][nc] == 'E') ? 0 : (board[nr][nc] - '0');
                        int new_score = current_score + edge_val;

                        if (new_score > dp_score[nr][nc]) {
                            dp_score[nr][nc] = new_score;
                            dp_paths[nr][nc] = current_paths;
                        } else if (new_score == dp_score[nr][nc]) {
                            dp_paths[nr][nc] = (dp_paths[nr][nc] + current_paths) % MOD;
                        }
                    }
                }
            }
        }

        if (dp_score[0][0] == -1) return {0, 0};
        return {dp_score[0][0], dp_paths[0][0]};
    }
};
