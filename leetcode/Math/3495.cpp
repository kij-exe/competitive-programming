//
// Created by Mykyta on 9/9/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // count how many reduces all numbers [0..num] need
    long long countReduces(long long num) {
        long long count = 0;
        long long i = 1, prevPower = 1, largestPower = 4;
        while (num >= prevPower) {
            count += i * (min(largestPower, num + 1) - prevPower);
            prevPower *= 4;
            largestPower *= 4;
            i++;
        }
        return count;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (const auto &query : queries) {
            int l = query[0], r = query[1];
            result += (countReduces(r) - countReduces(l - 1) + 1) / 2;
        }
        return result;
    }
};