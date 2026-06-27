//
// Created by Mykyta on 10/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // prefixCount[i] = number of 'a's - 'b's in s[0..i)
    vector<int> prefixCount(n + 1);
    // prefixCountMap[i] the latest index of
    // value i in the prefixCount
    prefixCount[0] = 0;
    // we want te select a subarray to remove which would
    // the total difference be 0
    for (int i = 0; i < n; i++) {
        prefixCount[i + 1] = prefixCount[i];
        if (s[i] == 'a') {
            prefixCount[i + 1]++;
        }
        else {
            prefixCount[i + 1]--;
        }
    }
    map<int, int> prefixCountMap;
    prefixCountMap[0] = 0;
    int minSubArray = n;
    for (int i = 1; i <= n; i++) {
        // the diff for the suffix not including i
        int rightDiff = prefixCount[n] - prefixCount[i];
        prefixCountMap[prefixCount[i]] = i;
        // to make total diff 0, select prefix at j
        // such that prefixCount[j] + rightDiff = 0
        // so we want to look up the latest j, s.t.
        // prefixCount[j] = -rightDiff
        if (prefixCountMap.contains(-rightDiff)) {
            minSubArray = min(minSubArray, i - prefixCountMap[-rightDiff]);
        }
    }
    if (minSubArray == n) {
        cout << -1 << endl;
    }
    else {
        cout << minSubArray << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
