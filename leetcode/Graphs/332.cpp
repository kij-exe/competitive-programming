//
// Created by Mykyta on 9/13/2025.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const string START_AIRPORT = "JFK";
    // first explore the most lexicographically smallest path
    // add nodes in the reverse order
    // if some cities have not been visited yet,
    // it means that they form cycles with the first city
    // so they must be traversed first before going on the
    // lexicographically smallest path
    // adding cities in reverse order allows to account for this
    static void dfs(const string &curr, unordered_map<string, vector<string>> &adjMap, vector<string> &res) {
        while (!adjMap[curr].empty()) {
            const string& nextAirport = adjMap[curr].back();
            adjMap[curr].pop_back();
            dfs(nextAirport, adjMap, res);
        }
        res.push_back(curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjMap;
        for (const auto& ticket : tickets) {
            const string &from = ticket[0], &to = ticket[1];
            adjMap[from].push_back(to);
        }
        for (auto &destinations: adjMap | views::values) {
            ranges::sort(destinations, [](const string &a, const string &b) {
                return a > b;
            });
        }
        vector<string> res;
        dfs(START_AIRPORT, adjMap, res);
        ranges::reverse(res);
        return res;
    }
};