//
// Created by Mykyta on 9/8/2025.
//
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n, 0);
        for (int i = 1; i <= n / 2; i++) {
            res[i - 1] = i;
            res[n - i] = -i;
        }
        return res;
    }
};