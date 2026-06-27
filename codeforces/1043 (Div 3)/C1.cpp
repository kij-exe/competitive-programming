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
    ll n;
    cin >> n;
    vector<ll> pow3(22);
    vector<ll> cost(22);
    pow3[0] = 1;
    cost[0] = 3;
    for (ll i = 1; i <= 21; i++) {
        pow3[i] = pow3[i - 1] * 3;
        cost[i] = pow3[i] * 3 + i * pow3[i - 1];
    }
    ll totalCost = 0;
    for (int i = 20; i >= 0; i--) {
        totalCost += (n / pow3[i]) * cost[i];
        n %= pow3[i];
    }
    cout << totalCost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
