//
// Created by Mykyta on 10/19/2025.
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int pMax = a[0];
    for(int i = 1; i < n; i++) {
        pMax = max(pMax, a[i]);
        if ((i + 1) % 2 == 0) {
            a[i] = pMax;
        }
    }
    ll total = 0;
    for (int i = 0; i < n; i += 2) {
        int left = i > 0 ? a[i - 1] : INT_MAX;
        int right = i < (n - 1) ? a[i + 1] : INT_MAX;
        total += max(0, a[i]  + 1 - min(left, right));
    }
    cout << total << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
