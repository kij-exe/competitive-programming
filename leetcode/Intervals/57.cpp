#include <algorithm>
#include <vector>
//
// Created by Mykyta on 7/19/2025.
//
class Solution {
    bool intersect(vector<int> int1, vector<int> int2) {
        return min(int1[1], int2[1]) >= max(int1[0], int2[0]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;
        for (vector<int> interval: intervals) {
            if (intersect(newInterval, interval)) {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
                continue;
            }
            if (!inserted && interval[0] > newInterval[1]) {
                inserted = true;
                result.push_back(newInterval);
            }
            result.push_back(interval);
        }
        if (!inserted) {
            result.push_back(newInterval);
        }
        return result;
    }
};
