//
// Created by Mykyta on 7/19/2025.
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool hasTarget = false;
            for (int i = 0; i <= n - mid; ++i) {
                if (prefixSum[i + mid] - prefixSum[i] >= target) {
                    hasTarget = true;
                    break;
                }
            }
            if (hasTarget) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left == n + 1 ? 0 : left;
    }
};
