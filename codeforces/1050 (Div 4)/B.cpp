//
// Created by Mykyta on 9/18/2025.
//
#include <bits/stdc++.h>

#define NMAX 1000000001
#define MOD 1000000007
using namespace std;
using ll = long long;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cout << n + m << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
