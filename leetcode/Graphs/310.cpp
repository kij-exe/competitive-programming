//
// Created by Mykyta on 9/13/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());
        vector<int> indegree(n, 0);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        unordered_set<int> level;
        vector<bool> visited(n, false);
        int visitedNum = 0;
        // add all leaves to the level
        for (int i = 0; i < n; i++) {
            if (indegree[i] <= 1) {
                level.insert(i);
                visited[i] = true;
                visitedNum++;
            }
        }
        while (visitedNum < n) {
            unordered_set<int> nextLevel;
            for (const int node: level) {
                // remove a node from a tree by removing it from indegree count
                // of neighbour nodes
                for (const int neighbour: adjList[node]) {
                    if (!visited[neighbour]) {
                        indegree[neighbour]--;
                        // if neighbour's indegree became 1
                        // it becomes a leaf now
                        if (indegree[neighbour] == 1) {
                            nextLevel.insert(neighbour);
                            visited[neighbour] = true;
                            visitedNum++;
                        }
                    }
                }
            }
            level = move(nextLevel);
        }
        return vector<int>(level.begin(), level.end());
    }
};