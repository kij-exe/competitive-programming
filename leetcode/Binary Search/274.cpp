#include <algorithm>
//
// Created by Mykyta on 7/16/2025.
//
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int lo = 0, hi = 1000;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            for (int citation: citations) {
                if (citation >= mid) {
                    count++;
                }
            }
            if (count >= mid) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return hi;
    }
};
