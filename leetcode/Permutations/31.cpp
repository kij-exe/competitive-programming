//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        // find the first pair in unsorted order
        while (i > 0) {
            if (nums[i - 1] < nums[i]) {
                // find the smallest number in the suffix
                // that is greater than nums[i - 1]
                // it will be in the head of a new suffix
                int least_larger_num_id = i;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] <= nums[i - 1]) break;
                    least_larger_num_id = j;
                }
                const int temp = nums[i - 1];
                nums[i - 1] = nums[least_larger_num_id];
                nums[least_larger_num_id] = temp;
                break;
            }
            i--;
        }
        // reverse the remaining suffix
        // so that it forms the lexicographically smallest sequence
        for (int j = 0; i + j < nums.size() - 1 - j; j++) {
            const int temp = nums[i + j];
            nums[i + j] = nums[nums.size() - j - 1];
            nums[nums.size() - j - 1] = temp;
        }
    }
};
