//
// Created by Mykyta on 8/28/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), k = 'z' - 'a' + 1;
        vector<int> firstOcc(k, -1), lastOcc(k, -1);
        for (int i = 0; i < n; i++) {
            if (firstOcc[s[i] - 'a'] == -1) {
                firstOcc[s[i] - 'a'] = i;
            }
            lastOcc[s[i] - 'a'] = i;
        }
        vector<int> res;
        pair<int, int> currentInterval = {firstOcc[s[0] - 'a'], lastOcc[s[0] - 'a']};
        for (int i = 0; i < n; i++) {
            if (i > currentInterval.second) {
                res.push_back(currentInterval.second - currentInterval.first + 1);
                currentInterval = {firstOcc[s[i] - 'a'], lastOcc[s[i] - 'a']};
            } else {
                currentInterval.second = max(currentInterval.second, lastOcc[s[i] - 'a']);
            }
        }
        res.push_back(currentInterval.second - currentInterval.first + 1);
        return res;
    }
};
