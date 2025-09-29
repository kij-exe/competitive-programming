//
// Created by Mykyta on 9/22/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 998244353
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll count = 2;
    for (int i = 1; i < n; i++) {
        ll nextCount = 0;
        // elements already form a non-decreasing array
        // then we know that there is at least the same number of
        // subsets to choose as for an array without the last elements
        if (a[i - 1] <= a[i] && b[i - 1] <= b[i]) {
            nextCount += count;
        }
        // if swapping elements still forms a non-decreasing array
        // then the number of ways is doubled
        // although each case is independent, it could be the case
        // that regardless of swaps, it's impossible to form such array
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i]) {
            nextCount += count;
        }
        count = nextCount % MOD;
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
