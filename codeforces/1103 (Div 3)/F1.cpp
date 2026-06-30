
#include <bits/stdc++.h>
using namespace std;

#define NMAX 500001
#define MOD 1000000007
using ll = long long;

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

void mulSelf(ll& a, ll b) {
    a = (a * b) % MOD;
}

ll mul(ll a, ll b) {
    mulSelf(a, b);
    return a;
}

void addSelf(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll add(ll a, ll b) {
    addSelf(a, b);
    return a;
}

ll spf[NMAX + 1];

void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll k = a[i];
        while (k != 1) {
            mp[spf[k]]++;
            k /= spf[k];
        }
    }
    ll total = 1;
    for (auto& el: mp) {
        mulSelf(total, el.second + 1);
    }
    cout << total << endl;
}

int main() {
    for (int i = 2; i <= NMAX; i++) {
        if (spf[i] != 0) continue;
        for (int j = i; j <= NMAX; j += i) {
            if (spf[j] == 0) {
                spf[j] = i;
            }
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
}
