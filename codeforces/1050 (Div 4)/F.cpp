//
// Created by Mykyta on 9/19/2025.
//
#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int maxLength = 0;
    vector<vector<int>> arrays, relevantArray;
    // relevantArray[i] - a set of indices of all arrays that
    // have the length - 1 >= i (have index i in their range)
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        arrays.emplace_back(k);
        for (int j = 0; j < k; j++) {
            cin >> arrays.back()[j];
            if (j >= relevantArray.size()) {
                relevantArray.emplace_back();
            }
            relevantArray[j].push_back(i);
        }
        maxLength = max(maxLength, k);
    }
    vector<int> result(maxLength);
    // bestArray[i] = an index of the current best array
    // to pick to continue a prefix of length i
    vector<int> bestArray(maxLength);
    // rank[i] - position of a previous considered suffix of an array i
    // in the sorted order of their priorities
    vector<int> rank(n, -1);
    for (int i = maxLength - 1; i >= 0; i--) {
        vector<array<int, 3>> currentChoice;
        // sort currently considered arrays based on
        // 1) current element
        // 2) if current element is tied, compare their suffixes
        //    iterating backwards and keeping the rank of previous
        //    suffixes allows to avoid comparisons
        //    shorter arrays are preferred, so the rank of -1
        //    denotes that an array is shorter than i
        for (int j : relevantArray[i]) {
            currentChoice.push_back({arrays[j][i], rank[j], j});
        }
        ranges::sort(currentChoice);
        bestArray[i] = currentChoice[0][2];
        // update ranks for the next iteration
        for (int currRank = 0; currRank < currentChoice.size(); currRank++) {
            rank[currentChoice[currRank][2]] = currRank;
        }
    }
    int currPrefixLen = 0;
    while (currPrefixLen < maxLength) {
        vector<int>& currArray = arrays[bestArray[currPrefixLen]];
        for (int i = currPrefixLen; i < currArray.size(); i++) {
            result[i] = currArray[i];
        }
        currPrefixLen = currArray.size();
    }
    for (int elem: result) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
