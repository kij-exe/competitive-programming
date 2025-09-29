//
// Created by Mykyta on 9/10/2025.
//
#include <bits/stdc++.h>
using namespace std;
#define MODULO 1000000007

class Solution {
    long add(long a, long b) {
        return (a + b) % MODULO;
    }
    long sub(long a, long b) {
        return (a - b + MODULO) % MODULO;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);
        long window = 0;
        for (int i = 1; i <= n; i++) {
            if (i - delay > 0) {
                window = add(window, dp[i - delay]);
            }
            if (i - forget > 0) {
                window = sub(window, dp[i - forget]);
            }
            else {
                dp[i]++;
            }
            dp[i] = add(dp[i], window);
        }
        return dp[n];
    }
};
