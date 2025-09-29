//
// Created by Mykyta on 9/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int node) {
        visited[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visited[i]) {
                dfs(isConnected, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};