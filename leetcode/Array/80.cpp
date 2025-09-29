//
// Created by Mykyta on 7/15/2025.
//
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        // copy only if [i - 2] != [i]
        int n = nums.size();
        int i = 1, j = 1;
        int consecutive = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                consecutive++;
            }
            else {
                consecutive = 1;
            }
            if (consecutive <= 2) {
                nums[j++] = nums[i];
            }
            i++;
        }
        return j;
    }
};
