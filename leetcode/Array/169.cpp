//
// Created by Mykyta on 7/15/2025.
//
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int majority = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                majority = nums[i];
            }
            if (nums[i] == majority) {
                count++;
            }
            else {
                count--;
            }
        }
        return majority;
    }
};
