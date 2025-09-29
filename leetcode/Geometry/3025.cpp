//
// Created by Mykyta on 9/10/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>> &points) {
        int res = 0;
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        for (int i = 0; i < points.size(); i++) {
            const auto &pUpperLeft = points[i];
            // the range of y values of points between
            // upper left and lower right points
            int lowestY = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                const auto &pLowerRight = points[j];
                if (pLowerRight[1] > pUpperLeft[1]) continue;
                // check if the interval of encountered ys and
                // interval of rectangle ys intersect
                if (pLowerRight[1] > lowestY) {
                    res++;
                    lowestY = pLowerRight[1];
                }
            }
        }
        return res;
    }
};
