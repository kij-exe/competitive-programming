//
// Created by Mykyta on 9/18/2025.
//
#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), globalCount(n + 1, 0), currentCount(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        globalCount[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (globalCount[i] % k != 0) {
            cout << 0 << endl;
            return;
        }
        globalCount[i] /= k;
    }
    ll res = 0;
    int l = 0, r = 0;
    while (r < n) {
        currentCount[a[r]]++;
        while (currentCount[a[r]] > globalCount[a[r]]) {
            currentCount[a[l++]]--;
        }
        res += r - l + 1;
        r++;
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
