//
// Created by Mykyta on 9/5/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // view each bar as a start of a rectangle of the bar's height
        // extending as much as possible to the right
        // if a bar of smaller height is found, then the previous bar's
        // rectangle can't extend anymore, so we register it and remove it
        // however it also means that current bar's rectangle can start earlier
        const int n = heights.size();
        stack<pair<int, int>> s;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int rectStart = i;
            while (!s.empty() && s.top().first >= heights[i]) {
                auto [prevH, prevI] = s.top();
                s.pop();
                rectStart = prevI;
                maxArea = max(maxArea, prevH * (i - prevI));
            }
            s.push({heights[i], rectStart});
        }
        while (!s.empty()) {
            auto [prevH, prevI] = s.top();
            s.pop();
            maxArea = max(maxArea, prevH * (n - prevI));
        }
        return maxArea;
    }
};