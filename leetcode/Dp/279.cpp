//
// Created by Mykyta on 8/25/2025.
//
class Solution {
    int numSquareRec(int n, vector<int>& res) {
        if (res[n] != -1) return res[n];
        for (int i = 1; i * i <= n; i++) {
            int squareCountI = numSquareRec(n - i * i, res);
            if (res[n] == -1 || res[n] > squareCountI + 1) {
                res[n] = squareCountI + 1;
            }
        }
        return res[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        return numSquareRec(n, dp);
    }
};