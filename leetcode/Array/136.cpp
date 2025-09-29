//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int runningXor = 0;
        for (const int num: nums) {
            runningXor ^= num;
        }
        return runningXor;
    }
};