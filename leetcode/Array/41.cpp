//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // all numbers <= 0 or > n are irrelevant
        // first pass: clean the array to identify
        // empty spots
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1; // n + 1 - empty spot
            }
        }
        // second pass: for all numbers 1 <= num <= n
        // make nums[num - 1] negative
        // to indicate its presence
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n && nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            }
        }
        // then return the first i s.t. nums[i - 1] is positive
        // it will be the smallest positive integer that didn't appear
        // if no such integer is found, then initial array contained
        // all integers 1 to n, so the next one is n + 1
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > 0) {
                return i;
            }
        }
        return n + 1;
    }
};