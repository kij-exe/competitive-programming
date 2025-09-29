//
// Created by Mykyta on 7/19/2025.
//
class Solution {
    pair<int, int> dirs[8] = {{-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {0, -1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveArea = 0;
                for (pair<int, int> dir: dirs) {
                    int x = i + dir.first, y = j + dir.second;
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (board[x][y] >= 1) {
                        liveArea++;
                    }
                }
                if (board[i][j] >= 1) {
                    board[i][j] += liveArea;
                }
                else {
                    board[i][j] -= liveArea;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -3 || board[i][j] == 3 || board[i][j] == 4) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
};