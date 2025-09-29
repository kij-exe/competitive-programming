//
// Created by Mykyta on 9/20/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(k);
    for(int i = 0; i < k; i++) cin >> b[i];
    ranges::sort(a, greater());
    ranges::sort(b);
    ll total = 0;
    ll i = 0;
    for (ll voucher: b) {
        for (ll j = i; j < i + voucher - 1 && j < n; j++) {
            total += a[j];
        }
        i += voucher;
    }
    while (i < n) {
        total += a[i++];
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
