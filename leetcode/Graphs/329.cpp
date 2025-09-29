//
// Created by Mykyta on 9/13/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, int>> DIRS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int getLongestPath(vector<vector<int>> &matrix, vector<vector<int>> &longestPath, int row, int col) {
        if (longestPath[row][col] != 0) {
            return longestPath[row][col];
        }
        longestPath[row][col] = 1;
        for (const auto [dirRow, dirCol]: DIRS) {
            if (0 <= row + dirRow && row + dirRow < matrix.size() && 0 <= col + dirCol && col + dirCol < matrix[0].size() &&
                matrix[row + dirRow][col + dirCol] > matrix[row][col]) {
                longestPath[row][col] = max(longestPath[row][col], getLongestPath(matrix, longestPath, row + dirRow, col + dirCol) + 1);
            }
        }
        return longestPath[row][col];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> longestPath(n, vector<int>(m, 0));
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxLen = max(maxLen, getLongestPath(matrix, longestPath, i, j));
            }
        }
        return maxLen;
    }
};