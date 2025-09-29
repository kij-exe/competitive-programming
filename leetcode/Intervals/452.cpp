#include <algorithm>
#include <vector>
//
// Created by Mykyta on 7/20/2025.
//
class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        vector<int> currInterval = points[0];
        int intervals = 1;
        for (int i = 1; i < points.size(); i++) {
            currInterval = {max(currInterval[0], points[i][0]), min(currInterval[1], points[i][1])};
            if (currInterval[1] < currInterval[0]) {
                currInterval = points[i];
                intervals++;
            }
        }
        return intervals;
    }
};
