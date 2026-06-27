//
// Created by Mykyta on 10/8/2025.
//
#include <bits/stdc++.h>
using namespace std;

#define NMAX 1000000001
#define MOD 1000000007
using ll = long long;

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &x: a) out << x << ' ';
    return out;
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> res;
    ll denom = 11;
    while (denom <= n) {
        if (n % denom == 0) {
            res.push_back(n / denom);
        }
        denom = (denom - 1) * 10 + 1;
    }
    cout << res.size() << endl;
    ranges::reverse(res);
    if (res.size() > 0)
        cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
