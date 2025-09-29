#include <iostream>
//
// Created by Mykyta on 7/18/2025.
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0, j = 0;
        int min_length = 0;
        int left = 0, right = 0;
        while (j < nums.size()) {
            if (right - left >= target) {
                if (min_length == 0 || j - i < min_length) {
                    min_length = j - i;
                }
                left += nums[i++];
            } else {
                right += nums[j++];
            }
        }
        while (right - left >= target) {
            if (min_length == 0 || j - i < min_length) {
                min_length = j - i;
            }
            left += nums[i++];
        }
        return min_length;
    }
};
