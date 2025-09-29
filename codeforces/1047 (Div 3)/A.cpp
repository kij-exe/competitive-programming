//
// Created by Mykyta on 9/24/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void solve() {
    int x, k;
    cin >> k >> x;
    cout << x * (1 << k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
